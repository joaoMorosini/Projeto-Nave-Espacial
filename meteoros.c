#include "aviao.h"
#include <stdio.h>
#include <curses.h>
#include <time.h>


void blocos(meteoro * bloco){
    int aux = 0;
    int j = 0;
    //quadrado
    for (aux = bloco->estado; aux < bloco->estado+bloco->tamanho; aux++){
        for (j = bloco->x; j < bloco->x+5; j++){
             mvaddch(aux, j, ACS_BLOCK);
        }
    }

}
void lanternas(meteoro * lanterna){
    int aux = 0;
    int j = 0;
    //quadrado
    for (aux = lanterna->estado; aux < lanterna->estado+lanterna->tamanho; aux++){
        for (j = lanterna->x; j < lanterna->x+2; j++){
             mvaddch(aux, j, ACS_LANTERN);
        }
    }

}
void quadriculados(meteoro * quadriculado){
    int aux = 0;
    int j = 0;
    //quadrado
    for (aux = quadriculado->estado; aux < quadriculado->estado+quadriculado->tamanho; aux++){
        for (j = quadriculado->x; j < quadriculado->x+5; j++){
             mvaddch(aux, j, ACS_CKBOARD);
        }
    }

}
//triangulo inverso descendo
void triangulos(meteoro * triangulo){
    int x = triangulo->x;
        int y = triangulo->estado;
        int aux = 5;
        int cont = 1;
        //desenha o aviao
        for (int i = 0; i < triangulo->tamanho; i++){
            for (int j = 0; j < aux; j++){
                mvaddch(y, x, ACS_DIAMOND);
                x--;
            }
            x = triangulo->x - cont;
            cont++;
            aux = aux - 2;
            y++;
        }

}

void circulos(meteoro * circulo){
    int y = circulo->estado;
    int x = circulo->x;
    int cont = 1;
    int aux = 2;
    //quadrado
        for (int i = 0; i < circulo->tamanho; i++){
                for (int j = 0; j < aux; j++){
                     mvaddch(y, x, ACS_BLOCK);
                     x++;
                }
                if (i >= 2){
                cont = cont - 2;
                aux = aux -4;
                }

                x = circulo->x - cont;
                cont++;
                aux+=2;
                y++;
        }




}

