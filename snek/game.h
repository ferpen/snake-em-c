//Definindo structs kobra
typedef struct kobra kobra;
typedef struct cabesa cabesa;
//protótipos das funções 
void logic();
void finalize();
void imput();
void cnfg();
void gerafrut();
void move();
void criakobra();
void aumentakobra(kobra *corpo);
void movekobra(kobra *corpo);
void mordekobra(kobra *corpo);
void libera(kobra *corpo);

//estrutura da cobra
struct cabesa
{
    int posi[2];
    kobra *filho;
};

//estrutura do corpo
struct kobra
{
    int posi[2];
    kobra *filho;
};

//configurações do jogo
void cnfg(){
    player.posi[0] = in[0];
    player.posi[1] = in[1];
    gerafrut();
}

//funcionamento do jogo
void logic(){
    int x;
    
    //move a cobra
    move();

    //caso bata na borda
    if(player.posi[1]==-1|| player.posi[1]==hei || player.posi[0]==-1 || player.posi[0]==wid)
    finalize();

    //caso pegue a fruta
    if(player.posi[0]==frut[0]&&player.posi[1]==frut[1]){
    score++;
    gerafrut();
    if (player.filho == NULL){
    criakobra();
    }
    else
    aumentakobra(player.filho);
    }
    if (player.filho!= NULL)
    mordekobra(player.filho);
    
}

//termina o jogo
void finalize(){
    system("cls");
    printf("Voce Perdeu :(\n");
    printf("score final : %d\n",score);
    printf("pressione 'z' para voltar ao menu");
    while(key != 5){
    imput();
}
    game=0;
    score=0;
    key=0;
    if (player.filho!= NULL)
    libera(player.filho);
    if (player.filho!=NULL)
    player.filho=NULL;
}

//gera a posição da fruta
void gerafrut(){
    srand(time(NULL));
    frut[0]=rand()%hei;
    frut[1]=rand()%wid; 
}

//move a cobra
void move(){

    if (player.filho!=NULL){
    movekobra(player.filho); // move o corpo
    player.filho->posi[0]=player.posi[0];
    player.filho->posi[1]=player.posi[1];
    }

    //move a cabeça
    if(key==1)
    player.posi[0]--;
    if (key==3)
    player.posi[0]++;
    if (key==2)
    player.posi[1]--;
    if (key==4)
    player.posi[1]++;
    
}

//aumenta o tamango do corpo
void aumentakobra(kobra *corpo){
   if (corpo->filho==NULL){
    corpo->filho= malloc(sizeof(kobra));
    corpo->filho->filho=NULL;
   }
   else
   aumentakobra(corpo->filho);
}

//move o corpo da cobra
void movekobra (kobra *corpo){
    if (corpo->filho!=NULL){
        movekobra(corpo->filho);
    corpo->filho->posi[0]=corpo->posi[0];
    corpo->filho->posi[1]=corpo->posi[1];
    }

    }
    //cria o corpo
    void criakobra(){
        player.filho=malloc(sizeof(kobra));
        player.filho->filho=NULL;
    }

    //confere se a cobra se mordeu
    void mordekobra(kobra *corpo){
        if (corpo->filho != NULL)
        mordekobra(corpo->filho);
        if((corpo->posi[1]==player.posi[1]) && (corpo->posi[0]==player.posi[0]))
        finalize();
    }

    //libera memória
    void libera(kobra *corpo){
        if (corpo->filho != NULL)
        libera (corpo->filho);

        free(corpo);

        if (corpo->filho != NULL)
        corpo->filho = NULL;
    }