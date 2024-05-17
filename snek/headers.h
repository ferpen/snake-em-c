
//Variáveis globais
int  key,game=0;              //key = tecla pressionada // game = qual parte do programa está rodando
int  hei=10,wid=10;           //tamanho do campo do jogo (altura e largura)
struct cabesa player;         // posição da cabeça da cobra
int frut[2] ={5,5};                  //posição fruta
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
void config();
void coptions(int i);
void cchoice(int x,int i);
//---------------------------
//Menu do jogo
void menu(){

 //declarando variáveis locais

 int x = 0,i,n=3; //n = número de opções

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
switch (x)
{
case 0:
    game=1;
    cnfg();
    break;
case 1:
    game =2;
    break;
case 2:
    game=3;
    break;
}

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
        printf("configurcoes\n");
        break;
        case 2:
        printf("sair\n\n");
    }
}

//----------------------------
void config (){
int quit =0,i,n=3,x=0;
do{
 key=0;  //isso é para impedir que uma tecla pressionada seja imputada mais de uma vez
 system("cls");
 printf("#####################\n\n");
 printf("SNEK GAIME\n\n");
 for (i=0;i<n;i++){
    cchoice(x,i);
    coptions(i);
 } 
 printf("#####################\n");

 while(key==0){
imput();
 }

//se for s a opção escolhida aumenta
 if (key== 3 && x<n-1)
    x++;

//se for w a opção escolhida diminui
 if (key == 1 && x>0)
    x--;

 if (x!=2)
 key=0;
}while (key!=5);
game = 0;
}
void coptions(int i){
    switch (i)
    {
    case 0:
        printf("altura do campo : %d\n",wid);
        break;
    
    case 1:
        printf("largura do campo : %d\n",hei);
        break;
    case 2:
        printf("voltar ao menu\n\n");
    }
}

void cchoice(int x,int i){
    if (x==i)
    printf("-> ");
    else
    printf("   ");
}