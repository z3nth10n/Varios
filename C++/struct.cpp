#include "C:\includes\ivancea.h"

void* makeStruct(string type){ //int,string
    int count=0;
    for(int i=0; i<type.size(); i++)
        if(contains(type,"int",i)){
            count+=4;
            i+=3;
        }else if(contains(type,"string",i)){
            count+=4;
            i+=6;
        }
    void* mem = malloc(count);
    count=0;
    for(int i=0; i<type.size(); i++)
        if(contains(type,"int",i)){
            *((int*)(mem+count))=0;
            count+=4;
            i+=3;
        }else if(contains(type,"string",i)){ //Se guarda puntero a string
            *((string**)(mem+count))=new string();
            count+=4;
            i+=6;
        }
    return mem;
}

int getInt(string type, void* st, int index){
    int count=0, i=0;
    for(i=0; i<type.size(); i++)
        if(contains(type,"int",i)){
            if(count==index) break;
            count++;
            i+=3;
        }else if(contains(type,"string",i)){
            if(count==index) throw exc("Invalid index of struct (get): " + parseInt(index));
            count++;
            i+=6;
        }
    return *((int*)(st+4*index));
}

string getString(string type, void* st, int index){
    int count=0, i=0;
    for(i=0; i<type.size(); i++)
        if(contains(type,"int",i)){
            if(count==index) throw exc("Invalid index of struct (get): " + parseInt(index));
            count++;
            i+=3;
        }else if(contains(type,"string",i)){
            if(count==index) break;
            count++;
            i+=6;
        }
    return **((string**)(st+4*index));
}

void setInt(string type, void* st, int index, int value){
    int count=0, i=0;
    for(i=0; i<type.size(); i++)
        if(contains(type,"int",i)){
            if(count==index) break;
            count++;
            i+=3;
        }else if(contains(type,"string",i)){
            if(count==index) throw exc("Invalid index of struct (set): " + parseInt(index));
            count++;
            i+=6;
        }
    *((int*)(st+4*index))=value;
}

void setString(string type, void* st, int index, string value){
    int count=0, i=0;
    for(i=0; i<type.size(); i++)
        if(contains(type,"int",i)){
            if(count==index) throw exc("Invalid index of struct (set): " + parseInt(index));
            count++;
            i+=3;
        }else if(contains(type,"string",i)){
            if(count==index) break;
            count++;
            i+=6;
        }
    **((string**)(st+4*index))=value;
}

#define CONTACT "string,int,string" //Nombre,Numero,Mail
#define CONTACT_NAME 0
#define CONTACT_NUMBER 1
#define CONTACT_MAIL 2

int main(){
    void* a = makeStruct(CONTACT);
    try{
        setString(CONTACT,a,0,"Hola, que tal");
        cout << getString(CONTACT,a,0);
    }catch(exception &e){
        cout << endl << e.what() << endl;
    }
}
