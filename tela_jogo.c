#include "aviao.h"
#include <stdio.h>
#include <curses.h>
#include <time.h>

//atualiza Tela
void drawScreen(aviao * aviao, tiro * tiro1,tiro * tiro2, tiro * tiro3, meteoro * bloco, meteoro * lanterna, meteoro * quadriculado, meteoro * triangulo, meteoro * circulo, pontuacao * pontuacao, statusTela * statusTela)
{

    clear();
    if (statusTela->tela_mostrar == -1){
        desenhoion();
        desenhojogar();
        desenhoscore();
        desenhoajuda();
        desenhosair();
        desenhonome();
    }
  else if (statusTela->tela_mostrar == 1){
     /* printw("\nEngenharia de Computacao!\n");
    if(aviao->tecla_clicada != -1)
        printw("Ultima tecla: %d", aviao->tecla_clicada);*/
        desenharLimites(aviao);
        desenharAviao(aviao);
        leArqPontos();
        int *v = NULL;
        pontuacao->tam_num = 0;
        v = inverterNum(pontuacao);
        //le o arquivo com o número a partir do valor encontrado na posição do vetor
        for (int j = 0; j < pontuacao->tam_num; j++){
        if (v[j] == 0){
             leArq("num_0.txt", pontuacao);

        }
        else if (v[j] == 1){
             leArq("num_1.txt", pontuacao);

        }
        else if (v[j] == 2){
             leArq("num_2.txt", pontuacao);

        }
       else if (v[j] == 3){
             leArq("num_3.txt", pontuacao);

        }
     else if (v[j] == 4){
             leArq("num_4.txt", pontuacao);

        }
         else if (v[j] == 5){
             leArq("num_5.txt", pontuacao);

        }
         else if (v[j] == 6){
             leArq("num_6.txt", pontuacao);

        }
         else if (v[j] == 7){
             leArq("num_7.txt", pontuacao);

        }
         else if (v[j] == 8){
             leArq("num_8.txt", pontuacao);

        }
         else if (v[j] == 9){
             leArq("num_9.txt", pontuacao);

        }

        pontuacao->pos_x+= 7;

        }
        pontuacao->pos_x = 91;




        //atira e faz os blocos descer apenas quando clicado na tecla p
    if (aviao->ultima_tecla == 112){
            //faz o tiro sair da mesma posicao em x que o avião e também quando atirar n faz o tiro acompanhar o avião
            if (tiro1->y == 0){
                 tiro1->x = aviao->pos_x;
            }
                if (tiro2->y == 0){
                  tiro2->x = aviao->pos_x -1;
            }

                  if (tiro3->y == 0){
                   tiro3->x = aviao->pos_x + 1;
            }
            //faz os tiro sair a partir da posiçao do avião
             if (pontuacao->ponto == 10){
                 tiro2->x = aviao->pos_x - 1;
                tiro2->y = aviao->pos_y - 1;
                tiro2->controla_vel = aviao->pos_y - 1;
                tiro2->velocidade = 5;

                // tiro 3 - direita
                tiro3->x = aviao->pos_x + 1;
                tiro3->y = aviao->pos_y - 1;
                tiro3->controla_vel = aviao->pos_y - 1;
                tiro3->velocidade = 5;
            }



            //faz o tiro subir até a parte superior da tela
            tiro1->controla_vel -=1;
            tiro2->controla_vel-=1;
            tiro3->controla_vel-=1;
            atirar(tiro1, tiro2, tiro3, pontuacao);
            //condicao para descer só um ponto em y a cada 1 segundo
            if (bloco->y == bloco->estado){
                bloco->estado = bloco->y;
            }
                bloco->y+=1;
                blocos(bloco);

            //condicao para descer só um ponto em y a cada 1 segundo
            if (lanterna->estado == lanterna->y){
                 lanterna->estado = lanterna->y;
            }

                lanterna->y+=1;
                lanternas(lanterna);

             //condicao para descer só um ponto em y a cada 1 segundo
            if (quadriculado->estado == quadriculado->y){
                 quadriculado->estado = quadriculado->y;
            }

                quadriculado->y+=1;
                quadriculados(quadriculado);


            //condicao para descer só um ponto em y a cada 1 segundo
            if (triangulo->estado == triangulo->y){
                 triangulo->estado = triangulo->y;
            }

                triangulo->y+=1;
                triangulos(triangulo);


             //condicao para descer só um ponto em y a cada 1 segundo
            if (circulo->estado == circulo->y){
                 circulo->estado = circulo->y;
            }

                circulo->y+=1;
                circulos(circulo);

    destruirBloco(aviao, tiro1,tiro2, tiro3, bloco, pontuacao);
    destruirLanterna(aviao,tiro1,tiro2, tiro3, lanterna, pontuacao);
    destruirQuadriculados(aviao,tiro1,tiro2, tiro3, quadriculado, pontuacao);
    destruirCirculo(aviao,tiro1,tiro2, tiro3, circulo, pontuacao);
    destruirTriangulo(aviao, tiro1,tiro2, tiro3, triangulo, pontuacao);

    }


    //faz atirar novamente - tiro 1
   if (tiro1->y == 0){
    tiro1->y = aviao->pos_y;
    tiro1->controla_vel = aviao->pos_y;
   }
   //velocidade do tiro
   if (tiro1->controla_vel == tiro1->y-tiro1->velocidade){
    tiro1->controla_vel = tiro1->y;
    tiro1->y-=1;
   }

if (pontuacao->ponto > 10){
    //tiro 2
    if (tiro2->y == 0){
    tiro2->y = aviao->pos_y -1 ;
      tiro2->controla_vel = aviao->pos_y - 1;
   }

   //velocidade
    if (tiro2->controla_vel == tiro2->y-tiro2->velocidade){
    tiro2->controla_vel = tiro2->y;
    tiro2->y-=1;
   }

   //tiro 3

    if (tiro3->y == 0){
    tiro3->y = aviao->pos_y -1 ;
      tiro3->controla_vel = aviao->pos_y - 1;
   }
   //velocidade
   if (tiro3->controla_vel == tiro3->y-tiro3->velocidade){
    tiro3->controla_vel = tiro3->y;
    tiro3->y-=1;
   }
}



   //controle de velocidade bloco
   if (bloco->y == bloco->estado+bloco->velocidade){
    bloco->y = bloco->estado+1;
    bloco->estado +=1;

   }
   //faz o bloco descer novamente de uma posição aleatória
   if(bloco->estado == 31){
     bloco->estado = 0;
     bloco->y = 0;
    bloco->x = rand() % 70 + 10;
   }

    //faz com que o bloco desça somente quando o bloco->y seja igual ao bloco->estado mais 30
   if (lanterna->y == lanterna->estado+lanterna->velocidade){
    lanterna->y = lanterna->estado+1;
    lanterna->estado +=1;

   }
   //faz o bloco descer novamente de uma posição aleatória
   if(lanterna->estado == 31){
     lanterna->estado = -5;
     lanterna->y = -5;
    lanterna->x = rand() % 70 + 10;
   }


 //faz com que o bloco desça somente quando o bloco->y seja igual ao bloco->estado mais 30
   if (quadriculado->y == quadriculado->estado+quadriculado->velocidade){
    quadriculado->y = quadriculado->estado+1;
    quadriculado->estado +=1;
   }
   //faz o bloco descer novamente de uma posição aleatória
   if(quadriculado->estado == 31){
     quadriculado->estado = 0;
     quadriculado->y = 0;
    quadriculado->x = rand() % 70 + 10;
   }

   //faz com que o bloco desça somente quando o bloco->y seja igual ao bloco->estado mais 30
   if (triangulo->y == triangulo->estado+triangulo->velocidade){
    triangulo->y = triangulo->estado+1;
    triangulo->estado +=1;
   }
   //faz o bloco descer novamente de uma posição aleatória
   if(triangulo->estado == 31){
     triangulo->estado = 0;
     triangulo->y = 0;
     triangulo->x = rand() % 70 + 15;
   }

    //faz com que o bloco desça somente quando o bloco->y seja igual ao bloco->estado mais 30
   if (circulo->y == circulo->estado+circulo->velocidade){
    circulo->y = circulo->estado+1;
    circulo->estado +=1;
   }
   //faz o bloco descer novamente de uma posição aleatória
   if(circulo->estado == 31){
     circulo->estado = 0;
     circulo->y = 0;
     circulo->x = rand() % 70 + 12;

   }
    refresh();
  }

}

//pega entradas do usuario
void handleInputs(aviao * aviao, statusTela * statusTela)
{
    int entrada = getch();

    if(entrada != -1)
        aviao->tecla_clicada = entrada;
   if (aviao->tecla_clicada == '1'){
    statusTela->tela_mostrar = 1;
   }
    switch(aviao->tecla_clicada)
    {
        case 260:
        if (aviao->pos_x-4 > 10){
             aviao->pos_x = aviao->pos_x-1;

        }
            aviao->tecla_clicada = -1;
    break;
        case 261:
            if (aviao->pos_x+4 < 90){
                 aviao->pos_x = aviao->pos_x+1;

            }
            aviao->tecla_clicada = -1;

    break;
        case 259:
            //
            if ( aviao->pos_y > 0){
                aviao->pos_y = aviao->pos_y-1;
            }

    aviao->tecla_clicada = -1;
    break;
        case 258:
            //verificação de minimo
             if ( aviao->pos_y < 26){
                 aviao->pos_y = aviao->pos_y+1;
            }
            aviao->tecla_clicada = -1;
        break;
    //tecla p: atirar
        case 112:
            // deixa o numero entre 10 e 90
            aviao->ultima_tecla = aviao->tecla_clicada;
            aviao->tecla_clicada = -1;
       break;
    }

}
void desenharAviao(aviao * aviao){
        int x = aviao->pos_x;
        int y = aviao->pos_y;
        int aux = 1;
        int cont = 1;
        //desenha o aviao
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < aux; j++){
                mvaddch(y, x, ACS_BLOCK);
                x++;
            }
            x = aviao->pos_x - cont;
            cont++;
            aux = aux + 2;
            y++;
        }
}
void desenharLimites(aviao * aviao){
    int rows, cols;
    // funcao que pega a quantidade de linhas e colunas do terminal para pode fazer os limites.
    getmaxyx(stdscr, rows, cols);
   // printw("%d %d", rows, cols);
    for (int i = 0; i < rows; i++){
         mvaddch(i, 10, ACS_BLOCK);
         mvaddch(i, cols - 30, ACS_BLOCK);
    }
}
void atirar(tiro * tiro1, tiro * tiro2, tiro * tiro3, pontuacao * pontuacao){
         mvaddch(tiro1->y, tiro1->x, ACS_BLOCK);
         if (pontuacao->ponto > 10){
             mvaddch(tiro2->y, tiro2->x, ACS_BLOCK);
             mvaddch(tiro3->y, tiro3->x, ACS_BLOCK);
         }

}

void somarPontos(pontuacao * pontuacao){
  pontuacao->ponto++;

}
//descobre quantas vezes será feita a divisão, aloca memoria pra um vetor e coloca cada algarismo dentro de uma posição do vetor para poder escrever na tela
int inverterNum(pontuacao * p){
 int div = 0;
 int resto = 0;
 int aux = p->ponto;
 while(1){
    div = aux/10;
    resto = aux;
    p->tam_num++;
    if (div == 0){
        break;
    }
    aux = div;
 }
 aux = p->ponto;
 int * v = malloc(p->tam_num*sizeof(int));
 for (int j = p->tam_num-1; j > -1; j--){
    div = aux/10;
    int ver = aux%10;
    v[j] = aux%10;
    aux = div;
 }
 return v;
}



















