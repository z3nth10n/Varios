#include "ivancea.h"

void tetris(int velocity=200){
    note(4, LA, velocity*2);
    note(4, MI, velocity*1);
    note(4, FA, velocity*1);

    note(4, SOL, velocity*2);
    note(4, FA, velocity*1);
    note(4, MI, velocity*1);

    note(4, RE, velocity*2);
    note(4, RE, velocity*1);
    note(4, FA, velocity*1);

    note(4, LA, velocity*2);
    note(4, SOL, velocity*1);
    note(4, FA, velocity*1);

    note(4, MI, velocity*2);
    note(4, MI, velocity*1);
    note(4, FA, velocity*1);

    note(4, SOL, velocity*2);
    note(4, LA, velocity*2);

    note(4, FA, velocity*2);
    note(4, RE, velocity*2);

    note(4, RE, velocity*4);

    thSleep(velocity);
    note(4, SOL, velocity*2);
    note(4, LA_S, velocity*1);

    /*****************************************************/

    note(5, RE, velocity*1);
    note(5, RE, velocity*1);
    note(4, DO, velocity*1);
    note(4, LA_S, velocity*1);

    note(4, LA, velocity*3);
    note(4, FA, velocity*1);

    note(4, LA, velocity*1);
    note(4, LA, velocity*1);
    note(4, SOL, velocity*1);
    note(4, FA, velocity*1);

    note(4, MI, velocity*2);
    note(4, MI, velocity*1);
    note(4, FA, velocity*1);

    note(4, SOL, velocity*2);
    note(4, LA, velocity*2);

    note(4, FA, velocity*2);
    note(4, RE, velocity*2);

    note(4, RE, velocity*4);
}

void himnoAleman(int velocity=200){
    note(4, FA, velocity*2);
    note(4, FA, velocity*2);
    note(4, MI, velocity*2);

    note(4, RE, velocity*6);
    note(4, FA, velocity*2);

    note(4, SI, velocity*3);
    note(4, LA, velocity*1);
    note(4, SOL, velocity*2);
    note(4, RE, velocity*2);

    note(4, FA, velocity*4);
    note(4, MI, velocity*4);

    /******************************/

    thSleep(velocity*2);
    note(4, MI, velocity*2);
    note(4, MI, velocity*2);
    note(4, RE, velocity*2);

    note(4, DO, velocity*6);
    note(4, FA, velocity*2);

    note(4, FA, velocity*3);
    note(4, FA, velocity*1);
    note(4, SOL, velocity*2);
    note(4, FA, velocity*2);

    note(4, RE, velocity*6);
    thSleep(velocity*2);

    for(int i=0; i<2; i++){

        thSleep(velocity*2);
        note(4, FA, velocity*2);
        note(4, RE, velocity*2);
        note(4, FA, velocity*2);

        note(4, SI, velocity*3);
        note(5, RE, velocity*1);
        note(5, RE, velocity*2);
        note(5, RE, velocity*2);

        note(5, DO, velocity*2);
        note(4, SI, velocity*2);
        note(4, LA, velocity*2);
        note(4, SI, velocity*2);

        note(5, MI, velocity*4);
        note(5, MI, velocity*4);

        /******************************/

        thSleep(velocity*2);
        note(5, DO, velocity*2);
        note(4, SI, velocity*2);
        note(4, SI, velocity*2);

        note(5, RE, velocity*6);
        note(4, SI, velocity*2);

        note(4, LA, velocity*3);
        note(4, LA, velocity*1);
        note(4, SOL, velocity*2);
        note(4, LA, velocity*2);

        note(4, SI, velocity*6);
        thSleep(velocity*2);
    }
}

void himnoSovietico(int velocity=200){

    note(4, SOL, velocity*2);
    for(int i=0; i<2; i++){

        note(5, DO, velocity*4);
        note(4, SOL, velocity*3);
        note(4, LA, velocity*1);

        note(4, SI, velocity*4);
        note(4, MI, velocity*2);
        note(4, MI, velocity*2);

        note(4, LA, velocity*4);
        note(4, SOL, velocity*3);
        note(4, FA, velocity*1);

        note(4, SOL, velocity*4);
        note(4, DO, velocity*2);
        note(4, DO, velocity*2);

        /****************************************/

        note(4, RE, velocity*4);
        note(4, RE, velocity*2);
        note(4, MI, velocity*2);

        note(4, FA, velocity*4);
        note(4, FA, velocity*2);
        note(4, SOL, velocity*2);

        note(4, LA, velocity*4);
        note(4, SI, velocity*2);
        note(5, DO, velocity*2);

        note(5, RE, velocity*6);
        note(4, SOL, velocity*2);

        note(5, MI, velocity*4);
        note(5, RE, velocity*3);
        note(5, DO, velocity*1);

        /****************************************/

        note(5, RE, velocity*4);
        note(4, SI, velocity*2);
        note(4, SOL, velocity*2);

        note(5, DO, velocity*4);
        note(4, SI, velocity*3);
        note(4, LA, velocity*1);

        note(4, SI, velocity*4);
        note(4, MI, velocity*2);
        note(4, MI, velocity*2);

        note(4, LA, velocity*4);
        note(4, SOL, velocity*2);
        note(4, FA, velocity*2);

        note(4, SOL, velocity*4);
        note(4, DO, velocity*2);
        note(4, DO, velocity*2);

        /**************************************/

        note(5, DO, velocity*4);
        note(4, SI, velocity*3);
        note(4, LA_S, velocity*1);

        note(4, SOL, velocity*8);

        note(5, MI, velocity*8);
        note(5, RE, velocity*2);
        note(5, DO, velocity*2);
        note(4, SI, velocity*2);
        note(5, DO, velocity*2);

        note(5, RE, velocity*6);
        note(4, SOL, velocity*2);
        note(4, SOL, velocity*8);

        /***************************************/
        /***************************************/

        note(5, DO, velocity*8);
        note(4, SI, velocity*2);
        note(4, LA, velocity*2);
        note(4, SOL, velocity*2);
        note(4, LA, velocity*2);

        note(4, SI, velocity*6);
        note(4, MI, velocity*2);
        note(4, MI, velocity*4);
        thSleep(velocity*4);

        note(5, DO, velocity*4);
        note(4, LA, velocity*3);
        note(4, SI, velocity*1);
        note(5, DO, velocity*4);
        note(4, LA, velocity*3);
        note(4, SI, velocity*1);

        /***************************************/

        note(5, DO, velocity*4);
        note(4, LA, velocity*2);
        note(5, DO, velocity*2);
        note(5, FA, velocity*6);
        thSleep(velocity*2);

        note(5, FA, velocity*8);
        note(5, MI, velocity*2);
        note(5, RE, velocity*2);
        note(5, DO, velocity*2);
        note(5, RE, velocity*2);

        note(5, MI, velocity*6);
        note(5, DO, velocity*2);
        note(5, DO, velocity*8);

        /****************************************/

        note(5, RE, velocity*8);
        note(5, DO, velocity*2);
        note(4, SI, velocity*2);
        note(4, LA, velocity*2);
        note(4, SI, velocity*2);

        note(5, DO, velocity*6);
        note(4, LA, velocity*2);
        note(4, LA, velocity*8);

        note(5, DO, velocity*4);
        note(4, SI, velocity*2);
        note(4, LA, velocity*2);
        note(4, SOL, velocity*4);
        note(4, DO, velocity*3);
        note(4, DO, velocity*1);

        if(!i){

            note(5, DO, velocity*4);
            note(4, SI, velocity*3);
            note(4, LA, velocity*1);
            note(4, SOL, velocity*4);
            thSleep(velocity*2);
            note(4, SOL, velocity*2);

        }else{/*****************/

            note(4, SOL, velocity*8);
            note(4, LA, velocity*4);
            note(4, SI, velocity*4);

            note(5, DO, velocity*12);
            thSleep(velocity*4);

        }
    }
}

void tetris(bool &on, int velocity=200){
    note(4, LA, velocity*2);
    note(4, MI, velocity*1);
    note(4, FA, velocity*1);
    while(!on) thSleep(10);

    note(4, SOL, velocity*2);
    note(4, FA, velocity*1);
    note(4, MI, velocity*1);
    while(!on) thSleep(10);

    note(4, RE, velocity*2);
    note(4, RE, velocity*1);
    note(4, FA, velocity*1);
    while(!on) thSleep(10);

    note(4, LA, velocity*2);
    note(4, SOL, velocity*1);
    note(4, FA, velocity*1);
    while(!on) thSleep(10);

    note(4, MI, velocity*2);
    note(4, MI, velocity*1);
    note(4, FA, velocity*1);
    while(!on) thSleep(10);

    note(4, SOL, velocity*2);
    note(4, LA, velocity*2);
    while(!on) thSleep(10);

    note(4, FA, velocity*2);
    note(4, RE, velocity*2);
    while(!on) thSleep(10);

    note(4, RE, velocity*4);
    while(!on) thSleep(10);

    thSleep(velocity);
    note(4, SOL, velocity*2);
    note(4, LA_S, velocity*1);
    while(!on) thSleep(10);

    /*****************************************************/

    note(5, RE, velocity*1);
    note(5, RE, velocity*1);
    note(4, DO, velocity*1);
    note(4, LA_S, velocity*1);
    while(!on) thSleep(10);

    note(4, LA, velocity*3);
    note(4, FA, velocity*1);
    while(!on) thSleep(10);

    note(4, LA, velocity*1);
    note(4, LA, velocity*1);
    note(4, SOL, velocity*1);
    note(4, FA, velocity*1);
    while(!on) thSleep(10);

    note(4, MI, velocity*2);
    note(4, MI, velocity*1);
    note(4, FA, velocity*1);
    while(!on) thSleep(10);

    note(4, SOL, velocity*2);
    note(4, LA, velocity*2);
    while(!on) thSleep(10);

    note(4, FA, velocity*2);
    note(4, RE, velocity*2);
    while(!on) thSleep(10);

    note(4, RE, velocity*4);
    while(!on) thSleep(10);
}

void himnoAleman(bool &on, int velocity=200){
    note(4, FA, velocity*2);
    note(4, FA, velocity*2);
    note(4, MI, velocity*2);
    while(!on) thSleep(10);

    note(4, RE, velocity*6);
    note(4, FA, velocity*2);
    while(!on) thSleep(10);

    note(4, SI, velocity*3);
    note(4, LA, velocity*1);
    note(4, SOL, velocity*2);
    note(4, RE, velocity*2);
    while(!on) thSleep(10);

    note(4, FA, velocity*4);
    note(4, MI, velocity*4);
    while(!on) thSleep(10);

    /******************************/

    thSleep(velocity*2);
    note(4, MI, velocity*2);
    note(4, MI, velocity*2);
    note(4, RE, velocity*2);
    while(!on) thSleep(10);

    note(4, DO, velocity*6);
    note(4, FA, velocity*2);
    while(!on) thSleep(10);

    note(4, FA, velocity*3);
    note(4, FA, velocity*1);
    note(4, SOL, velocity*2);
    note(4, FA, velocity*2);
    while(!on) thSleep(10);

    note(4, RE, velocity*6);
    thSleep(velocity*2);
    while(!on) thSleep(10);

    for(int i=0; i<2; i++){

        thSleep(velocity*2);
        note(4, FA, velocity*2);
        note(4, RE, velocity*2);
        note(4, FA, velocity*2);
    while(!on) thSleep(10);

        note(4, SI, velocity*3);
        note(5, RE, velocity*1);
        note(5, RE, velocity*2);
        note(5, RE, velocity*2);
    while(!on) thSleep(10);

        note(5, DO, velocity*2);
        note(4, SI, velocity*2);
        note(4, LA, velocity*2);
        note(4, SI, velocity*2);
    while(!on) thSleep(10);

        note(5, MI, velocity*4);
        note(5, MI, velocity*4);
    while(!on) thSleep(10);

        /******************************/

        thSleep(velocity*2);
        note(5, DO, velocity*2);
        note(4, SI, velocity*2);
        note(4, SI, velocity*2);
    while(!on) thSleep(10);

        note(5, RE, velocity*6);
        note(4, SI, velocity*2);
    while(!on) thSleep(10);

        note(4, LA, velocity*3);
        note(4, LA, velocity*1);
        note(4, SOL, velocity*2);
        note(4, LA, velocity*2);
    while(!on) thSleep(10);

        note(4, SI, velocity*6);
        thSleep(velocity*2);
    }
}
void himnoSovietico(bool &on, int velocity=200){

    note(4, SOL, velocity*2);
    for(int i=0; i<2; i++){
    while(!on) thSleep(10);

        note(5, DO, velocity*4);
        note(4, SOL, velocity*3);
        note(4, LA, velocity*1);
    while(!on) thSleep(10);

        note(4, SI, velocity*4);
        note(4, MI, velocity*2);
        note(4, MI, velocity*2);
    while(!on) thSleep(10);

        note(4, LA, velocity*4);
        note(4, SOL, velocity*3);
        note(4, FA, velocity*1);
    while(!on) thSleep(10);

        note(4, SOL, velocity*4);
        note(4, DO, velocity*2);
        note(4, DO, velocity*2);
    while(!on) thSleep(10);

        /****************************************/

        note(4, RE, velocity*4);
        note(4, RE, velocity*2);
        note(4, MI, velocity*2);
    while(!on) thSleep(10);

        note(4, FA, velocity*4);
        note(4, FA, velocity*2);
        note(4, SOL, velocity*2);
    while(!on) thSleep(10);

        note(4, LA, velocity*4);
        note(4, SI, velocity*2);
        note(5, DO, velocity*2);
    while(!on) thSleep(10);

        note(5, RE, velocity*6);
        note(4, SOL, velocity*2);
    while(!on) thSleep(10);

        note(5, MI, velocity*4);
        note(5, RE, velocity*3);
        note(5, DO, velocity*1);
    while(!on) thSleep(10);

        /****************************************/

        note(5, RE, velocity*4);
        note(4, SI, velocity*2);
        note(4, SOL, velocity*2);
    while(!on) thSleep(10);

        note(5, DO, velocity*4);
        note(4, SI, velocity*3);
        note(4, LA, velocity*1);
    while(!on) thSleep(10);

        note(4, SI, velocity*4);
        note(4, MI, velocity*2);
        note(4, MI, velocity*2);
    while(!on) thSleep(10);

        note(4, LA, velocity*4);
        note(4, SOL, velocity*2);
        note(4, FA, velocity*2);
    while(!on) thSleep(10);

        note(4, SOL, velocity*4);
        note(4, DO, velocity*2);
        note(4, DO, velocity*2);
    while(!on) thSleep(10);

        /**************************************/

        note(5, DO, velocity*4);
        note(4, SI, velocity*3);
        note(4, LA_S, velocity*1);
    while(!on) thSleep(10);

        note(4, SOL, velocity*8);
    while(!on) thSleep(10);

        note(5, MI, velocity*8);
        note(5, RE, velocity*2);
        note(5, DO, velocity*2);
        note(4, SI, velocity*2);
        note(5, DO, velocity*2);
    while(!on) thSleep(10);

        note(5, RE, velocity*6);
        note(4, SOL, velocity*2);
        note(4, SOL, velocity*8);
    while(!on) thSleep(10);

        /***************************************/
        /***************************************/

        note(5, DO, velocity*8);
        note(4, SI, velocity*2);
        note(4, LA, velocity*2);
        note(4, SOL, velocity*2);
        note(4, LA, velocity*2);
    while(!on) thSleep(10);

        note(4, SI, velocity*6);
        note(4, MI, velocity*2);
        note(4, MI, velocity*4);
        thSleep(velocity*4);
    while(!on) thSleep(10);

        note(5, DO, velocity*4);
        note(4, LA, velocity*3);
        note(4, SI, velocity*1);
        note(5, DO, velocity*4);
        note(4, LA, velocity*3);
        note(4, SI, velocity*1);
    while(!on) thSleep(10);

        /***************************************/

        note(5, DO, velocity*4);
        note(4, LA, velocity*2);
        note(5, DO, velocity*2);
        note(5, FA, velocity*6);
        thSleep(velocity*2);
    while(!on) thSleep(10);

        note(5, FA, velocity*8);
        note(5, MI, velocity*2);
        note(5, RE, velocity*2);
        note(5, DO, velocity*2);
        note(5, RE, velocity*2);
    while(!on) thSleep(10);

        note(5, MI, velocity*6);
        note(5, DO, velocity*2);
        note(5, DO, velocity*8);
    while(!on) thSleep(10);

        /****************************************/

        note(5, RE, velocity*8);
        note(5, DO, velocity*2);
        note(4, SI, velocity*2);
        note(4, LA, velocity*2);
        note(4, SI, velocity*2);
    while(!on) thSleep(10);

        note(5, DO, velocity*6);
        note(4, LA, velocity*2);
        note(4, LA, velocity*8);
    while(!on) thSleep(10);

        note(5, DO, velocity*4);
        note(4, SI, velocity*2);
        note(4, LA, velocity*2);
        note(4, SOL, velocity*4);
        note(4, DO, velocity*3);
        note(4, DO, velocity*1);
    while(!on) thSleep(10);

        if(!i){

            note(5, DO, velocity*4);
            note(4, SI, velocity*3);
            note(4, LA, velocity*1);
            note(4, SOL, velocity*4);
            thSleep(velocity*2);
            note(4, SOL, velocity*2);

        }else{/*****************/

            note(4, SOL, velocity*8);
            note(4, LA, velocity*4);
            note(4, SI, velocity*4);

            note(5, DO, velocity*12);
            thSleep(velocity*4);

        }
    while(!on) thSleep(10);
    }
}
