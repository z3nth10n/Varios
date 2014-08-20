#ifndef INI_H
#define INI_H

#include <fstream>
#include <map>


std::string readIni(std::string filePath, std::string key){
    std::ifstream file(filePath,std::ios::binary);
    std::string t;
    if(!file || key.size()==0) return t;
    while(file){
        getline(file,t);
        if(t.substr(0,key.size()+1)==key+"=")
            return t.substr(key.size()+1,t.size());
    }
    return t;
}

std::map<std::string,std::string> readIni(std::string filePath){
    std::fstream file(filePath,std::ios::in|std::ios::binary);
    std::map<std::string,std::string> ini;
    std::string t;
    while(file){
        getline(file,t);
        if(t.size()==0 || t[0]=='=') continue;
        size_t pos = t.find('=');
        if(pos==t.npos)
            ini[t.substr(0,pos)];
        else
            ini[t.substr(0,pos)] = t.substr(pos+1,t.size());
    }
    return ini;
}

bool writeIni(std::string filePath, std::string key, std::string value){
    if(key.size()==0 || key.find('=')!=key.npos) return false;
    std::map<std::string,std::string> ini = readIni(filePath);
    ini[key]=value;
    std::fstream file(filePath,std::ios::out|std::ios::binary|std::ios::trunc);
    if(!file.good())
        return false;
    for(auto it:ini)
        file.write((it.first+'='+it.second+"\r\n").c_str(),it.first.size()+it.second.size()+3);
    return true;
}

bool writeIni(std::string filePath, std::pair<std::string,std::string> key_value){
    return writeIni(filePath,key_value.first,key_value.second);
}

bool writeIni(std::string filePath, std::map<std::string,std::string> key_values){
    if(key_values.size()==0) return false;
    std::map<std::string,std::string> ini = readIni(filePath);
    ini.insert(key_values.begin(), key_values.end());
    std::fstream file(filePath,std::ios::out|std::ios::binary|std::ios::trunc);
    if(!file.good())
        return false;
    for(auto it:ini)
        file.write((it.first+'='+it.second+"\r\n").c_str(),it.first.size()+it.second.size()+3);
    return true;
}

#endif // INI_H
