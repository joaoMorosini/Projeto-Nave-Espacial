#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"


void leArqPontos(){
   FILE * pts = fopen("pontos.txt", "r");

   int y = 0;
   int x = 92;
   while (!feof(pts))
{
    //setColor(COLOR_CYAN,COLOR_BLACK,0);
    char a = fgetc(pts);
    move(y, x);
    printw("%c", a);
    x++;
    if (a == '\n'){
        y++;
        x = 92;
    }
}
fclose(pts);
}
void leArq(char * nome, pontuacao * pontuacao){
FILE * num = fopen(nome, "r");

 int y = 5;
 int x = pontuacao->pos_x;
      while (!feof(num))
    {
    char a = fgetc(num);

    move(y, x);
    printw("%c", a);
    x++;
    if (a == '\n'){
        y++;
        x = pontuacao->pos_x;
    }
    }
fclose(num);
}
