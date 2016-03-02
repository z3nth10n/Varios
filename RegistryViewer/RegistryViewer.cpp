#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <windows.h>

using namespace std;

bool compareBuffers(char* buff1, char* buff2, DWORD len1, DWORD len2){
	if(len1!=len2)
		return false;
	for(int i=0; i<len1; i++)
		if(buff1[i]!=buff2[i])
			return false;
	return true;
}

enum KeyTypes:char{
	ClassesRoot = 0,
	CurrentUser = 1,
	LocalMachine,
	Users,
	CurrentConfig
};

char readChar(istream& in){
	char c;
	in.read(&c, 1);
	return c;
}

int readInt(istream& in){
	int n;
	in.read((char*)&n, 4);
	return n;
}

string readString(istream& in){
	int n = readInt(in);
	if(n==0)
		return "";
	char* buff = new char[n];
	in.read(buff, n);
	string str(buff, n);
	delete[] buff;
	return str;
}

void readKey(istream& in, ostream& out, string path, HKEY key, bool onlyReadBuffer){
	char buffer[16500];
	DWORD k = sizeof(buffer);
	
	map<string, DWORD> values;
	DWORD valueDataSize;
	if(!onlyReadBuffer){
		for(int i=0; RegEnumValue(key, i, buffer, &k, NULL, NULL, NULL, &valueDataSize) == ERROR_SUCCESS; i++, k=sizeof(buffer)){
			values[string(buffer,k)] = valueDataSize;
		}
	}
	
	DWORD valueCount = readInt(in);
	
	for(int i=0; i<valueCount; i++){
		string valueName = readString(in);
		DWORD valueType = readInt(in);
		DWORD valueLength = readInt(in);
		char* valueBuff = new char[valueLength];
		in.read(valueBuff, valueLength);
		if(!onlyReadBuffer){
			auto it = values.find(valueName);
			if(it==values.end()){
				out << "Value disappeared: " << path << "/" << valueName << endl;
			}else{
				char *buff = new char[it->second];
				DWORD size = it->second;
				DWORD type;
				RegQueryValueEx(key, it->first.c_str(), NULL, &type, (unsigned char*)buff, &size);
				if(type!=valueType || !compareBuffers(buff, valueBuff, size, valueLength)){
					out << "Value changed: " << path << "/" << valueName << endl;
				}
				delete[] buff;
			}
			values.erase(it);
		}
		delete[] valueBuff;
	}
	if(!onlyReadBuffer){
		for(auto it:values){
			out << "Value appeared: " << path << "/" << it.first << endl;
		}
	}
	
	set<string> subKeyNames;
	if(!onlyReadBuffer){
		for(int i=0; RegEnumKeyEx(key, i, buffer, &k, NULL, NULL, NULL, NULL) == ERROR_SUCCESS; i++, k=sizeof(buffer)){
			subKeyNames.insert(string(buffer,k));
		}
	}
	
	DWORD keyCount = readInt(in);
	for(int i=0; i<keyCount; i++){
		string keyName = readString(in);
		auto it = subKeyNames.find(keyName);
		if(it==subKeyNames.end()){
			out << "Key disappeared: " << path << "/" << keyName << endl;
			readKey(in, out, "", NULL, true);
		}else{
			HKEY sub;
			int n = RegOpenKeyEx(key, it->c_str(), 0, KEY_READ, &sub);
			if(n!=ERROR_SUCCESS){
				char* errBuff;
				FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
							  FORMAT_MESSAGE_FROM_SYSTEM |
							  FORMAT_MESSAGE_IGNORE_INSERTS,
							  NULL, n,
							  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
							  (LPTSTR) &errBuff, 0, NULL);
				out << "Couldn't open key: " << path << "/" << it->c_str()
					<< "  --  Error: " << errBuff << endl;
				readKey(in, out, "", NULL, true);
			}else{
				readKey(in, out, path+"/"+keyName, sub, false);
				RegCloseKey(sub);
			}
			subKeyNames.erase(it);
		}
	}
	for(const string& str:subKeyNames){
		out << "Key appeared: " << path << "/" << str << endl;
	}
}

int compareRegistry(string rvlFile, string outFile){
	ifstream in(rvlFile, ios::binary);
	if(!in)
		return 1;
	ofstream out(outFile, ios::trunc);
	if(!out)
		return 2;
	
	cout << "Reading..." << endl;
	char type = readChar(in);
	HKEY hk;
	switch(type){
		case ClassesRoot:
			hk = HKEY_CLASSES_ROOT;
			break;
		case CurrentUser:
			hk = HKEY_CURRENT_USER;
			break;
		case LocalMachine:
			hk = HKEY_LOCAL_MACHINE;
			break;
		case Users:
			hk = HKEY_USERS;
			break;
		case CurrentConfig:
			hk = HKEY_CURRENT_CONFIG;
			break;
		default:
			return 2;
	}
	
	string path = readString(in);
	if(RegOpenKeyEx(hk, path.c_str(), 0, KEY_READ, &hk) != ERROR_SUCCESS){
		out << "Error: Inexistent key. (" << path << ")" << flush;
		return 3;
	}
	readKey(in, out, path, hk, false);
	
	RegCloseKey(hk);
	
	cout << "END" << endl;
	
	return 0;
}

void writeChar(ostream& out, char c){
	out.write(&c, 1);
}

void writeInt(ostream& out, int n){
	out.write((char*)&n, 4);
}

void writeString(ostream& out, string str){
	writeInt(out, str.size());
	out.write(str.c_str(), str.size());
}

void writeKey(ostream& out, HKEY key){
	
	char buffer[16500];
	DWORD k = sizeof(buffer);
	
	map<string, DWORD> values;
	DWORD valueDataSize;
	for(int i=0; RegEnumValue(key, i, buffer, &k, NULL, NULL, NULL, &valueDataSize) == ERROR_SUCCESS; i++, k=sizeof(buffer)){
		values[string(buffer,k)] = valueDataSize;
	}
	
	writeInt(out, values.size());
	for(auto it:values){
		char *buff = new char[it.second];
		DWORD size = it.second;
		DWORD type;
		RegQueryValueEx(key, it.first.c_str(), NULL, &type, (unsigned char*)buff, &size);
		writeString(out, it.first);
		writeInt(out, type);
		writeInt(out, it.second);
		out.write(buff, it.second);
		delete[] buff;
	}
	
	
	set<string> subKeyNames;
	for(int i=0; RegEnumKeyEx(key, i, buffer, &k, NULL, NULL, NULL, NULL) == ERROR_SUCCESS; i++, k=sizeof(buffer)){
		subKeyNames.insert(string(buffer,k));
	}
	writeInt(out, subKeyNames.size());
	for(string s:subKeyNames){
		HKEY sub;
		RegOpenKeyEx(key, s.c_str(), 0, KEY_READ, &sub);
		writeString(out, s);
		writeKey(out, sub);
		RegCloseKey(sub);
	}
}

int saveRegistry(KeyTypes type, string path, string fileName){
	ofstream out(fileName, ios::binary|ios::trunc);
	if(!out)
		return 1;
	HKEY hk;
	switch(type){
		case ClassesRoot:
			hk = HKEY_CLASSES_ROOT;
			break;
		case CurrentUser:
			hk = HKEY_CURRENT_USER;
			break;
		case LocalMachine:
			hk = HKEY_LOCAL_MACHINE;
			break;
		case Users:
			hk = HKEY_USERS;
			break;
		case CurrentConfig:
			hk = HKEY_CURRENT_CONFIG;
			break;
		default:
			return 2;
	}
	if(RegOpenKeyEx(hk, path.c_str(), 0, KEY_READ, &hk) != ERROR_SUCCESS)
		return 3;
	
	writeChar(out, type);
	writeString(out, path);
	writeKey(out, hk);
	
	RegCloseKey(hk);
	
	return 0;
}

int main(int argc, char** argv){
	if(argc==2){
		string name = argv[1];
		size_t p = name.rfind('\\'),
			   p2 = name.rfind('/');
		p = (p<p2 && p2!=string::npos?p2:p);
		if(p>=0)
			name = name.substr(p+1);
		if(name.size()>=1 && name[name.size()-1]=='"')
			name.erase(name.size()-1);
		name = "ChangesOf" + name + ".txt";
		cout << "Logging to \"" << name << "\"" << endl;
		int n = compareRegistry(argv[1], "ChangesOf" + name + ".txt");
		if(n!=0)
			cout << "Error: " << n << endl;
		
	}else{
		cout << "Starting..." << endl;
		cout << "HKCR: " << flush; cout << (saveRegistry(ClassesRoot,   "", "HKCR.rvl")==0?"OK":"ERROR") << endl;
		cout << "HKCU: " << flush; cout << (saveRegistry(CurrentUser,   "", "HKCU.rvl")==0?"OK":"ERROR") << endl;
		cout << "HKLM: " << flush; cout << (saveRegistry(LocalMachine,  "", "HKLM.rvl")==0?"OK":"ERROR") << endl;
		cout << "HKU:  " << flush; cout << (saveRegistry(Users,          "", "HKU.rvl")==0?"OK":"ERROR") << endl;
		cout << "HKCC: " << flush; cout << (saveRegistry(CurrentConfig, "", "HKCC.rvl")==0?"OK":"ERROR") << endl;
		cout << "END" << endl;
	}
	system("pause");
	return 0;
}

/******** FILE FORMAT ********* 
4 bytes: length
N bytes: data

[value]
string: name
4 bytes: type
4 bytes: length
N bytes: data

[key] OK
4 bytes: Value count
N values
4 bytes: Sub-key count
N {
	string: SubKey path
	key
}

[FILE] OK
1 byte: Key type (HKLM, HKCU, ...)
string: path
key
********************************/


/******** POSIBILITIES ********* 

-> Value appeared
-> Value disappeared
-> Value changed
-> Key appeared
-> Key dissapeared

********************************/
