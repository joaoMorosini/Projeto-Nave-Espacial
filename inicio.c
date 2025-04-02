#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include "aviao.h"

void desenhoion() //le o desemho
{

FILE *ion= fopen("ion.txt","r");

while (!feof(ion))
{
    setColor(COLOR_CYAN,COLOR_BLACK,0);
    char io = fgetc(ion);
    printw("%c",io);
}
fclose(ion);

}
void desenhojogar() // le o desenho
{
    FILE *jogar= fopen("Jogar.txt","r");
    while (!feof(jogar))
    {
        setColor(COLOR_RED,COLOR_BLACK,0);
        char jp = fgetc(jogar);
        printw ("%c",jp);
    }
    fclose(jogar);
}
void desenhoscore() // le o desenho
{
    FILE *score= fopen ("score.txt","r");
    while (!feof(score))
    {
        setColor (COLOR_RED,COLOR_BLACK,0);
        char sp = fgetc(score);
        printw("%c",sp);
    }
    fclose(score);
}
void desenhoajuda() // le o desenho
{
    FILE *ajuda= fopen("ajuda.txt","r");
    while (!feof(ajuda))
    {
        setColor(COLOR_YELLOW,COLOR_BLACK,0);
        char aj = fgetc(ajuda);
        printw("%c",aj);
    }
    fclose(ajuda);
}
void desenhosair () // le o desenho
{
    FILE *sair= fopen("sair.txt","r");
    while (!feof(sair))
    {
        setColor(COLOR_GREEN,COLOR_BLACK,0);
        char sa= fgetc(sair);
        printw("%c",sa);
    }
    fclose(sair);
}
void desenhonome()
{
    setColor (COLOR_WHITE,COLOR_BLACK,0);
    move (10,85);
    printw("Feito por:\n");
    move (11,85);
    printw("Gabriel Carvalho de Toledo e Silva\n");
    move (12,85);
    printw("Joao Morosini\n");
    move (13,85);
    printw("Lucas Koshita\n");

}

void creditos()
{
  FILE *credito= fopen("creditos.txt","r");
  while (!feof(credito))
  {
      setColor(COLOR_YELLOW,COLOR_BLACK,0);
      char cr = fgetc(credito);
      printw("%c", cr);
  }
  fclose(credito);
}

