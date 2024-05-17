#include "headers.h"


void main(int argc, char *argv[] ){
 
    do{
    switch (game){
        case 0:
        menu();
        break;

        case 1:
        draw();
        imput();
        Sleep(100);
        logic();
        break;

        case 2:
        config();
    }
 
    }while (game!=3);
}