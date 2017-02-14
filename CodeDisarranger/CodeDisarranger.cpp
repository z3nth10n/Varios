#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

bool isValidChar(char ch){
	return ch != ' ' && ch != '\t' && ch != '\r' && ch != '\n';
}

int main(int argc, char** argv){
	srand(time(0));
	if(argc != 2){
		cout << "First argument: file to disarrange" << endl;
	}else{
		fstream file(argv[1], ios::in);
		
		if(!file){
			cout << "Couldn't open the file" << endl;
		}else{
			file.seekg(0, ios::end);
			string data(file.tellg(), '\0');
			file.seekg(0);
			{
				size_t totalReaded = 0;
				while(file && totalReaded < data.size()){
					file.read(&data[totalReaded], data.size() - totalReaded);
					totalReaded += file.gcount();
				}
				data = data.substr(0, totalReaded);
			}
			file.close();
			
			size_t totalChars = 0;
			
			for(char c : data){
				totalChars += isValidChar(c);
			}
			
			for(int i=0; i<totalChars/10; i++){
				int randPos = rand()%(totalChars - i);
				
				for(int j=0; j<data.size(); j++){
					if(isValidChar(data[j])){
						if(randPos == 0){
							data.erase(j, 1);
							break;
						}
						
						randPos--;
					}
				}
			}
			
			file.open(argv[1], ios::out | ios::trunc);
			file.write(data.data(), data.size());
		}
	}
}
