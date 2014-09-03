#include <fstream>
#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>

using namespace std;

#define CHARS_NUM 2

int main(int args, char** argc){
    if(args==1){
        cout << "Por lo menos 1 archivo de parametro." << endl;
        cin.get();
        return 1;
    }
    char *chars = new char[CHARS_NUM];
    for(int i=1; i<args; i++){
        ifstream file(argc[i]);
        if(!file) continue;
        while(file){
            getch();
            file.read(chars,CHARS_NUM);
            cout.write(chars,file.gcount());
        }
        cout << endl;
    }
    cout << "Terminado!" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cin.get();
}