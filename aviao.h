#ifndef AVIAO_H_INCLUED
#define AVIAO_H_INCLUED

typedef struct aviao{
  int tecla_clicada;
  int pos_x;
  int pos_y;
  int ultima_tecla;
}aviao;

typedef struct tiro{
int x;
int y;
int controla_vel;
int velocidade;
}tiro;

typedef struct meteoro{
 int x;
 int y;
 int estado;
 int tamanho;
 int velocidade;
}meteoro;

typedef struct pontuacao{
int ponto;
int pos_x;
int tam_num;
}pontuacao;
typedef struct statusTela{
int tela_mostrar;
}statusTela;
void desenhoion();
void desenhojogar();
void desenhoscore();
void desenhoajuda();
void desenhosair();
void desenhonome();
void desenhomenu();
void creditos();
#endif // AVIAO_H_INCLUED
