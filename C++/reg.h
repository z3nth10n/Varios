#ifndef REG_H
#define REG_H

#include <string>
#include <windows.h>

void regAdd(HKEY type, std::string ruta, std::string valor, std::string data){
    HKEY key;
    RegCreateKey(type,ruta.c_str(),&key);
    RegSetValueEx(key, valor.c_str(), 0, REG_SZ, (const BYTE*)data.c_str(),data.size());
    RegCloseKey(key);
}

void regDel(HKEY type, std::string ruta, std::string valor){
    HKEY key;
    long lng = RegOpenKey(type,ruta.c_str(),&key);
    if(lng == ERROR_SUCCESS){
        RegDeleteValue(key, valor.c_str());
        RegCloseKey(key);
    }
}

std::string regRead(HKEY type, std::string ruta, std::string valor){
    HKEY key;
    TCHAR temp[1024];
    DWORD keyDataLength = 1024;
    std::string fin;
    long lng = RegOpenKey(type,ruta.c_str(),&key);
    if(lng == ERROR_SUCCESS){
        long error = RegQueryValueEx(key, valor.c_str(), NULL, NULL, (LPBYTE)&temp, &keyDataLength);
        RegCloseKey(key);
        if(error!=0) return "";
        for(int i=0; i<keyDataLength && temp[i]!='\0'; i++)
            fin += temp[i];
        return fin;
    }
    return "";
}

#endif // REG_H
