//protótipos de função
void campo();
void draw();
int conferecobra(int x,int y,kobra *corpo);

//desenhando o jogo
void draw(){
    
    system("cls");
    campo();

}

//cria a imagem após receber as coordenadas do jogador
void campo(){

    //declartando variáveis locais 
    int i,j,x;
    printf("score : %d fruta coord: %d,%d cobra coord %d,%d\n",score,frut[0],frut[1],player.posi[0],player.posi[1]);
    printf("endf %d\n",player.filho);
    
    for(i=-1;i<wid+1;i++){
        for (j=-1;j<hei+1;j++){
        if (player.posi[0]==i && player.posi[1]==j)     //se a posição da cobra for igual a parte do campo que está sendo criada, printa 0 (que representa a cabeça da cobra)
            printf("O");        
        else if (player.filho != NULL && (x=conferecobra(i,j,player.filho)) == 1)
            printf("o");
        else if (frut[0]==i && frut[1]==j)
            printf("*");
        else if(i==-1 || i==wid)
            printf("#");
        else if(j==-1 || j==hei)
            printf("#");
        else
            printf(" ");
        }
        printf("\n");
    }
    
}

//confere a posição do corpo
int conferecobra(int x,int y,kobra *corpo){
    int s;

    if (corpo->filho!=NULL){
    s=conferecobra(x,y,corpo->filho);
    }
  

    if (s==1)
    return 1;

    if(corpo->posi[0]==x && corpo->posi[1] == y)
    return 1;
    
    return 0;
}