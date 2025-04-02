// https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html

#include <curses.h>
#include <stdlib.h>
#include <time.h>
#include "aviao.h"
#include <windows.h>

// 8 colors for standard Curses

int main(int argc, char *argv[])
{
    // estrutura com dados internos da aplicação
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
    // inicializa a tela pelo Curses e o estado inicial da aplicação
    initScreen();
    initGame(&aviao, &tiro1, &tiro2, &tiro3, &bloco, &lanterna, &quadriculado, &triangulo, &circulo, &pontuacao, &statusTela);


    PlaySound ("musica.wav", NULL, SND_ASYNC | SND_FILENAME);
    //Laço principal sem retorno, pode ser removido para exibição direta de informação na tela
	while(1)
    {

        // Gerencia entradas do usuário pelo teclado
        handleInputs(&aviao, &statusTela);

        // Atualiza a tela
        drawScreen(&aviao, &tiro1, &tiro2, &tiro3, &bloco, &lanterna, &quadriculado, &triangulo, &circulo, &pontuacao, &statusTela);

        // Controla o FPS da aplicação
        napms(10);
    }

    // Encerra a tela inicializada em initScreen
    endwin();

	return 0;
}
