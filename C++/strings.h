#ifndef STRINGS_H
#define STRINGS_H

#include <vector>
#include <string>
#include <cmath>

std::string cesar(std::string temp, int b){
    if(b<0 || b>25) return temp;
    for(int i=0; i<temp.length();i++)
        if((unsigned char)temp[i]>=65 && (unsigned char)temp[i]<=90){
            temp[i]+=b;
            if(temp[i]>90) temp[i]-=26;
        }else
        if((unsigned char)temp[i]>=97 && (unsigned char)temp[i]<=122){
            temp[i]+=b;
            if((unsigned char)temp[i]>122) temp[i]-=26;
        }
    return temp;
}

bool contains(std::string contenedor, std::string cadena, int inicio){
    if(contenedor.size()<=inicio) return false;
    if(cadena.size()==0) return true;
    return contenedor.substr(inicio,cadena.size())==cadena;
}

int contains(std::string contenedor, std::string cadena){
    int temp = 0;
    if(contenedor.size()<cadena.size() || cadena.size()==0)
        return temp;
    for(int i=0; i+cadena.size()<=contenedor.size(); i++)
        if(contenedor.substr(i, cadena.size()) == cadena)
            ++temp;
    return temp;
}

std::vector<std::string> split(std::string inicial, std::string busqueda = " ", int maxc = -1){
    std::vector<std::string> temp;
    if(maxc==-1) maxc=inicial.size();
    if(inicial==""||busqueda==""||maxc<2){
        temp.push_back(inicial);
        return temp;
    }
    for(int i=0; i<inicial.size()&&temp.size()<maxc-1;)
        if(contains(inicial, busqueda, i)){
            if(i)
                temp.push_back(inicial.substr(0,i));
            inicial.erase(0, i+busqueda.size());
            i=0;
        }else ++i;
    temp.push_back(inicial);
    for(int i=0; i<temp.size(); i++)
        if(temp[i]=="") temp.erase(temp.begin()+i);
    return temp;
}

std::vector<std::string> split(std::string inicial, char busqueda = ' ', int maxc = -1){
    std::vector<std::string> temp;
    if(maxc==-1) maxc=inicial.size();
    if(inicial==""||maxc<2){
        temp.push_back(inicial);
        return temp;
    }
    for(int i=0; i<inicial.size()&&temp.size()<maxc-1;)
        if(inicial[i]==busqueda){
            if(i)
                temp.push_back(inicial.substr(0,i));
            inicial.erase(0, i+1);
            i=0;
        }else ++i;
    temp.push_back(inicial);
    for(int i=0; i<temp.size(); i++)
        if(temp[i]=="") temp.erase(temp.begin()+i);
    return temp;
}

bool equalIgnoreCase(std::string a, std::string b){
    if(a.size()!=b.size()) return 0;
    for(int i=0; i<a.size(); i++)
        if(toupper(a[i])!=toupper(b[i])) return false;
    return true;
}

void replaceAll(std::string &text, std::string find, std::string replace){
    std::string temp;
    for(int i=0; i<text.size(); i++){
        if(text.substr(i, find.size()) == find){
            temp += text.substr(0, i) + replace;
            text.erase(0, i+find.size());
            i=-1;
        }
    }
    text = temp+text;
}

void replaceAllIgnoreCase(std::string &text, std::string find, std::string replace){
    std::string temp;
    for(int i=0; i<text.size(); i++){
        if(equalIgnoreCase(text.substr(i, find.size()), find)){
            temp += text.substr(0, i) + replace;
            text.erase(0, i+find.size());
            i=-1;
        }
    }
    text = temp+text;
}

std::string toupper(std::string s){
    for(int i=0; i<s.size(); i++)
        s[i]=toupper(s[i]);
    return s;
}

std::string tolower(std::string s){
    for(int i=0; i<s.size(); i++)
        s[i]=tolower(s[i]);
    return s;
}

std::string trim(std::string s,char c=' '){
    int i=0;
    while(i<s.size() && s[i]==c)
        ++i;
    s.erase(0,i);
    i = s.size()-1;
    while(i>=0 && s[i]==c)
        --i;
    s.erase(i+1,s.size());
    return s;
}

bool isDec(std::string num){
    if(num.size()>=1)
        if(num[0]=='-') num[0]='0';
    for(int i=0; i<num.size(); i++)
        if(num[i]<'0' || num[i]>'9')
            return false;
    return true;
}

bool isHex(std::string num){
    if(num.size()>=1)
        if(num[0]=='-') num[0]='0';
    for(int i=0; i<num.size(); i++)
        if((num[i]<'0' || num[i]>'9') && (tolower(num[i])<'a' || tolower(num[i])>'f'))
            return false;
    return true;
}

std::string toHex(int a){
    std::string t;
    while(a>0){
        if(a%16>=0 && a%16<=9)
            t = (char)((a%16)+48) + t;
        else t = (char)((a%16)+55) + t;
        a=a/16;
    }
    return t;
}

#endif // STRINGS_H
