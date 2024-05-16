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
        logic();
        Sleep(100);
        break;
    }
 
    }while (game!=2);
}