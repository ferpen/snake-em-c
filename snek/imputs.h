void imput();

void imput(){
    if (kbhit()) {
        switch(getch()){

            case 'w':
            key=1;
            break;

            case 'a':
            key=2;
            break;

            case 's':
            key=3;
            break;

            case 'd':
            key=4;
            break;

            case 'z':
            key=5;
            break;
        }  
    }
}