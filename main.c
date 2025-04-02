// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html

#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "aviao.h"
#include <windows.h>

// 8 colors for standard Curses

int main(int argc, char *argv[])
{
    // estrutura com dados internos da aplica��o
    aviao aviao;
    tiro tiro1;
    tiro tiro2;
    tiro tiro3;
    meteoro bloco;
    meteoro lanterna;
    meteoro quadriculado;
    meteoro triangulo;
    meteoro circulo;
    pontuacao pontuacao;
    statusTela statusTela;
    // inicializa a tela pelo Curses e o estado inicial da aplica��o
    initScreen();
    initGame(&aviao, &tiro1, &tiro2, &tiro3, &bloco, &lanterna, &quadriculado, &triangulo, &circulo, &pontuacao, &statusTela);


    PlaySound ("musica.wav", NULL, SND_ASYNC | SND_FILENAME);
    //La�o principal sem retorno, pode ser removido para exibi��o direta de informa��o na tela
	while(1)
    {

        // Gerencia entradas do usu�rio pelo teclado
        handleInputs(&aviao, &statusTela);

        // Atualiza a tela
        drawScreen(&aviao, &tiro1, &tiro2, &tiro3, &bloco, &lanterna, &quadriculado, &triangulo, &circulo, &pontuacao, &statusTela);

        // Controla o FPS da aplica��o
        napms(10);
    }

    // Encerra a tela inicializada em initScreen
    endwin();

	return 0;
}
