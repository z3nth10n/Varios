#ifndef SELECTOR_H
#define SELECTOR_H

#include <iostream>
#include <vector>
#include <conio.h>

class options{
    std::vector<std::string> _options;
    std::string _title;

    void coutTitle()const{
        if(_title.size()==0) return;
        std::vector<std::string> v;
        std::string t = _title;
        bool lastN=false;
        while(t.size()>0){
            size_t pos = t.find('\n');
            if(pos!=t.npos && pos<80){
                if(pos==0 && !lastN){
                    t.erase(0,1);
                    lastN=true;
                    continue;
                }
                v.push_back(t.substr(0,pos));
                t.erase(0,pos+1);
                lastN=true;
            }else{
                lastN=false;
                v.push_back(t.substr(0,80));
                t.erase(0,80);
            }
        }
        //v.push_back(t);
        while(v.size()>0){
            std::cout << std::string((80-v[0].size())/2,' ') << v[0] << std::endl;
            v.erase(v.begin());
        }
        std::cout << std::endl;
    }

public:
    options(){}
    options(std::string title):_title(title){}
    options(const options& o):_options(o.getOptions()),_title(o.getTitle()){}
    void setTitle(std::string title){
        _title = title;
    }
    std::string getTitle()const{
        return _title;
    }
    std::vector<std::string> getOptions()const{
        return _options;
    }
    std::string getOption(size_t i)const{
        if(i<_options.size()) return _options[i];
        return "";
    }
    void addOption(std::string option){
        _options.push_back(option);
    }
    void addOptions(const std::vector<std::string>& v){
        for(int i=0; i<v.size(); i++)
            _options.push_back(v[i]);
    }
    void setOptions(const std::vector<std::string>& v){
        _options = v;
    }
    int show()const{
        int index = 0;
        char c = 0;
        while(c!='\r' && c!='\n'){
            system("cls");
            coutTitle();
            for(int i=0; i<_options.size(); i++){
                std::cout << '[' << (i==index?'X':' ') << "] " << _options[i] << std::endl;
            }
            c = getch();
            if((c=='w' || c=='W') && index>0)
                --index;
            if((c=='s' || c=='S') && index<_options.size()-1)
                ++index;
        }
        return index;
    }
};

#endif
