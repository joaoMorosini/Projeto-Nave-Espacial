#include "aviao.h"
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <windows.h>

void destruirBloco(aviao * aviao, tiro * tiro1, tiro * tiro2, tiro * tiro3,  meteoro * bloco, pontuacao * pontuacao){
    //verifica se o tiro 1 acertou
 if ((tiro1->y == bloco->estado) && (tiro1->x >= bloco->x && tiro1->x <= bloco->x+4)){
        bloco->tamanho-=1;
        tiro1->y = aviao->pos_y;
        tiro1->controla_vel = aviao->pos_y;
        tiro1->x = aviao->pos_x;
        somarPontos(pontuacao);
    }
    //verifica se o tiro 2 acertou
    if ((tiro2->y == bloco->estado) && (tiro2->x >= bloco->x && tiro2->x <= bloco->x+4)){
         bloco->tamanho-=1;
        tiro2->y = aviao->pos_y - 1;
        tiro2->controla_vel = aviao->pos_y - 1 ;
        tiro2->x = aviao->pos_x - 1;
        somarPontos(pontuacao);
    }
    //verifica se o tiro 3 acertou
     if ((tiro3->y == bloco->estado) && (tiro3->x >= bloco->x && tiro3->x <= bloco->x+4)){
         bloco->tamanho-=1;
        tiro3->y = aviao->pos_y - 1;
        tiro3->controla_vel = aviao->pos_y - 1 ;
        tiro3->x = aviao->pos_x + 1;
        somarPontos(pontuacao);
    }
    //quando o bloco é totalmente destruido volta ao tamanho normal
    if(bloco->tamanho <= 0){
        bloco->tamanho = 3;
        bloco->estado = 0;
       bloco->y = 0;
       bloco->x = rand() % 70 + 10;
    }
}
void destruirLanterna(aviao*  aviao, tiro * tiro1, tiro * tiro2, tiro * tiro3, meteoro * lanterna, pontuacao * pontuacao){
 if ((tiro1->y == lanterna->estado) && (tiro1->x >= lanterna->x && tiro1->x <= lanterna->x+1)){
        lanterna->tamanho-=1;
        tiro1->y = aviao->pos_y;
        tiro1->controla_vel = aviao->pos_y;
         tiro1->x = aviao->pos_x;
         somarPontos(pontuacao);
    }
    if ((tiro2->y == lanterna->estado) && (tiro2->x >= lanterna->x && tiro2->x <= lanterna->x+1)){
        lanterna->tamanho-=1;
        tiro2->y = aviao->pos_y - 1;
        tiro2->controla_vel = aviao->pos_y -1;
         tiro2->x = aviao->pos_x -1;
         somarPontos(pontuacao);
    }
    if ((tiro3->y == lanterna->estado) && (tiro3->x >= lanterna->x && tiro3->x <= lanterna->x+1)){
        lanterna->tamanho-=1;
        tiro3->y = aviao->pos_y - 1;
        tiro3->controla_vel = aviao->pos_y -1;
         tiro3->x = aviao->pos_x + 1;
         somarPontos(pontuacao);
    }
    //quando o bloco é totalmente destruido volta ao tamnho normal
    if(lanterna->tamanho <= 0){
        lanterna->tamanho = 3;
        lanterna->estado = 0;
        lanterna->y = 0;
        lanterna->x = rand() % 70 + 10;
    }
}

void destruirQuadriculados(aviao*  aviao,tiro * tiro1, tiro * tiro2, tiro * tiro3, meteoro * quadriculado, pontuacao * pontuacao){
 if ((tiro1->y == quadriculado->estado) && (tiro1->x >= quadriculado->x && tiro1->x <= quadriculado->x+4)){
        quadriculado->tamanho-=1;
        tiro1->y = aviao->pos_y;
        tiro1->controla_vel = aviao->pos_y;
        tiro1->x = aviao->pos_x;
        somarPontos(pontuacao);
    }
    if ((tiro2->y == quadriculado->estado) && (tiro2->x >= quadriculado->x && tiro2->x <= quadriculado->x+4)){
        quadriculado->tamanho-=1;
        tiro2->y = aviao->pos_y - 1;
        tiro2->controla_vel = aviao->pos_y - 1;
        tiro2->x = aviao->pos_x - 1;
        somarPontos(pontuacao);
    }
    if ((tiro3->y == quadriculado->estado) && (tiro3->x >= quadriculado->x && tiro3->x <= quadriculado->x+4)){
        quadriculado->tamanho-=1;
        tiro3->y = aviao->pos_y - 1;
        tiro3->controla_vel = aviao->pos_y - 1;
        tiro3->x = aviao->pos_x + 1;
        somarPontos(pontuacao);
    }
    //quando o bloco é totalmente destruido volta ao tamnho normal
    if(quadriculado->tamanho <= 0){
        quadriculado->tamanho = 3;
        quadriculado->estado = 0;
        quadriculado->y = 0;
        quadriculado->x = rand() % 70 + 10;
    }
}

void destruirTriangulo(aviao*  aviao,tiro * tiro1, tiro * tiro2, tiro * tiro3, meteoro * triangulo, pontuacao * pontuacao){
 if ((tiro1->y == triangulo->estado) && (tiro1->x >= triangulo->x-4 && tiro1->x <= triangulo->x)) {
        triangulo->tamanho-=1;
        tiro1->y = aviao->pos_y;
        tiro1->controla_vel = aviao->pos_y;
        tiro1->x = aviao->pos_x;
        somarPontos(pontuacao);
    }

    if ((tiro2->y == triangulo->estado) && (tiro2->x >= triangulo->x-4 && tiro2->x <= triangulo->x)) {
        triangulo->tamanho-=1;
        tiro2->y = aviao->pos_y - 1;
        tiro2->controla_vel = aviao->pos_y - 1;
        tiro2->x = aviao->pos_x - 1;
        somarPontos(pontuacao);
    }
    if ((tiro3->y == triangulo->estado) && (tiro3->x >= triangulo->x-4 && tiro3->x <= triangulo->x)) {
        triangulo->tamanho-=1;
        tiro3->y = aviao->pos_y -1;
        tiro3->controla_vel = aviao->pos_y-1;
        tiro3->x = aviao->pos_x + 1;
        somarPontos(pontuacao);
    }

    //quando o bloco é totalmente destruido volta ao tamnho normal
    if(triangulo->tamanho <= 0){
        triangulo->tamanho = 3;
        triangulo->estado = 0;
        triangulo->y = 0;
        triangulo->x = rand() % 70 + 10;
    }
}
void destruirCirculo(aviao * aviao, tiro * tiro1, tiro * tiro2, tiro * tiro3, meteoro * circulo, pontuacao * pontuacao){
 if ((tiro1->y == circulo->estado) && (tiro1->x >= circulo->x-2 && tiro1->x <= circulo->x+3)){
        circulo->tamanho-=1;
        tiro1->y = aviao->pos_y;
        tiro1->controla_vel = aviao->pos_y;
        tiro1->x = aviao->pos_x;
        somarPontos(pontuacao);
    }
    if ((tiro2->y == circulo->estado) && (tiro2->x >= circulo->x-2 && tiro2->x <= circulo->x+3)){
        circulo->tamanho-=1;
        tiro2->y = aviao->pos_y - 1;
        tiro2->controla_vel = aviao->pos_y - 1;
        tiro2->x = aviao->pos_x - 1;
        somarPontos(pontuacao);
    }
    if ((tiro3->y == circulo->estado) && (tiro3->x >= circulo->x-2 && tiro3->x <= circulo->x+3)){
        circulo->tamanho-=1;
        tiro3->y = aviao->pos_y - 1;
        tiro3->controla_vel = aviao->pos_y - 1;
        tiro3->x = aviao->pos_x + 1;
        somarPontos(pontuacao);
    }
    //quando o bloco é totalmente destruido volta ao tamnho normal
    if(circulo->tamanho <= 0){
        circulo->tamanho = 5;
        circulo->estado = 0;
       circulo->y = 0;
       circulo->x = rand() % 70 + 12;

    }
}
