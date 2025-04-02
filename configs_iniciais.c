#include "aviao.h"
#include <stdio.h>
#include <curses.h>

#define PALLETE_SIZE (COLOR_WHITE - COLOR_BLACK + 1)

void initScreen()
{
#ifdef XCURSES
    Xinitscr(argc, argv);
#else
    initscr();
#endif

    if (has_colors())
    {
        int bg = 0, fg = 0;

        start_color();

        for(bg = COLOR_BLACK; bg <= COLOR_WHITE; bg++)
            for(fg = COLOR_BLACK; fg <= COLOR_WHITE; fg++)
                init_pair(bg*PALLETE_SIZE + fg + 1, fg, bg); // color 0 is system default (reserved)
    }

    // Trata a tecla Enter como \n
    //nl();
    // Teclas digitadas pelo usuário não aparecem na tela

    noecho();
    // 0 para cursor invisível
    curs_set(0);
    // Define getch como non-blocking de acordo com o timeout abaixo
    nodelay(stdscr, TRUE);
    // Timeout em 0 determina getch como non-blocking, não espera entrada do usuário
    timeout(0);
    // Habilita teclas de function (F1, F2, ...), flechas, etc
    keypad(stdscr, TRUE);
}

void initGame(aviao * aviao, tiro * tiro1, tiro * tiro2, tiro * tiro3, meteoro * bloco, meteoro * lanterna, meteoro * quadriculado, meteoro * triangulo, meteoro * circulo, pontuacao * pontuacao, statusTela * statusTela)
{


    srand(time(NULL));
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    //aviao
    aviao->tecla_clicada = -1;
    aviao->ultima_tecla = -1;
    aviao->pos_x = 50;
    aviao->pos_y = 26;

    //status da tela inicial
    statusTela->tela_mostrar = -1;
    //tiro 1
    tiro1->x = aviao->pos_x;
    tiro1->y = aviao->pos_y;
    tiro1->controla_vel = aviao->pos_y;
    tiro1->velocidade = 5;

    // tiro 2 - esquerda
    tiro2->x = aviao->pos_x - 1;
    tiro2->y = aviao->pos_y - 1;
    tiro2->controla_vel = aviao->pos_y - 1;
    tiro2->velocidade = 5;

    // tiro 3 - direita
    tiro3->x = aviao->pos_x + 1;
    tiro3->y = aviao->pos_y - 1;
    tiro3->controla_vel = aviao->pos_y - 1;
    tiro3->velocidade = 5;


    //bloco-quadrado

    bloco->x= rand() % 80 + 10;
    bloco->y = 0;
    bloco->estado = 1;
    bloco->tamanho = 3;
    bloco->velocidade = 60;

    //bloco-laterna
    lanterna->x = rand() % 80 + 10;
    lanterna->y = -15;
    lanterna->estado = -15;
    lanterna->tamanho = 3;
    lanterna->velocidade = 50;

        //bloco-quadriculados
    quadriculado->x = rand() % 80 + 10;
    quadriculado->y = -80;
    quadriculado->estado = -80;
    quadriculado->tamanho = 3;
    quadriculado->velocidade = 40;

    //bloco-trangulares
    triangulo->x = rand() % 70 + 10;
    triangulo->y = -100;
    triangulo->estado = -100;
    triangulo->tamanho = 3;
    triangulo->velocidade = 30;

    //blocos-circulares
    circulo->x = rand() % 70 + 12;
    circulo->y = -200;
    circulo->estado = -200;
    circulo->tamanho = 5;
    circulo->velocidade = 20;
    //chama metodo para ler os numeros do arquivo e desenhar na tela

    //pontuação
    pontuacao->ponto = 0;
    pontuacao->pos_x = 91;
    pontuacao->tam_num = 0;
}

void setColor(short int fg, short int bg, chtype attr)
{
    chtype color = COLOR_PAIR(bg*PALLETE_SIZE + fg + 1);
    color |= attr;
    attrset(color);
}



