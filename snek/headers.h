
//Variáveis globais
int  key,game=0;              //key = tecla pressionada // game = qual parte do programa está rodando
int  hei=20,wid=20;           //tamanho do campo do jogo (altura e largura)
struct cabesa player;         // posição da cabeça da cobra
int frut[2];                  //posição fruta
int score = 0;                //pontuação no jogo
int in[2]={5,5};

//--------------------------
//Bibliotecas e cabeçalhos
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "game.h"
#include "draw.h"
#include "imputs.h"

//--------------------------

// protótipos de função
void options(int i);
void choice(int x,int i);
void menu();



//---------------------------
//Menu do jogo
void menu(){

 //declarando variáveis locais

 int x = 0,i,n=2; //n = número de opções

 //criando a interface

 do{

 key=0;  //isso é para impedir que uma tecla pressionada seja imputada mais de uma vez

 system("cls");
 printf("#####################\n\n");
 printf("SNEK GAIME\n\n");
 for (i=0;i<n;i++){
    choice(x,i);
    options(i);
 } 
 printf("#####################\n");
 printf("pressione 'z' para selecionar");
//recebe a tecla
while(key==0){
imput();
 }

//se for s a opção escolhida aumenta
 if (key== 3 && x<n-1)
    x++;

//se for w a opção escolhida diminui
 if (key == 1 && x>0)
    x--;

//se receber a tecla z sai do loop
}while (key !=5);

//quando sai do loop, dá um valor a game (no caso ou começa o jogo ou sai do loop principal, encerrando o programa)

if (x==0){
game=1;
cnfg();
}
else
game=2;
}

//recebe o valor de i (que representa a opção) e x (que representa a escolha), caso ambos tenham o mesmo valor, printa um X
void choice(int x,int i){
    if (x==i)
    printf("(X) ");
    else
    printf("( ) ");
}

//recebe o i (que representa as opções) e escreve o texto da opção de com o número correspondente
void options(int i){
    switch(i){
        case 0:
        printf("Jogar\n");
        break;
        case 1:
        printf("sair\n\n");
        break;
    }
}

//----------------------------
