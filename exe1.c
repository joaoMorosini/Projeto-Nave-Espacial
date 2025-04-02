/*
* Questão 1 (2,5pt)
*
* Aluno: DIGITE SEU NOME
* RA: DIGITE SEU RA
*
* Escreva a função limpaString que deverá receber um texto e um caractere.
* A função deve retornar uma nova string, alocada dinamicamente, com o
* caractere removido.
*/

char * limpaString(const char * str, char a)
{
    int i = 0;
    int aux = 0;
    while(1){
        if (str[i] == '\0'){
            break;
        }
        else if (str[i] != a && str[i] != '\n'){
            aux++;
        }
        i++;

    }
   char * v = (char*) malloc(aux*sizeof(char));

   aux = 0;
   for (int j = 0; j < i+1; j++){
    if (str[j]!=a){
        v[aux] = str[j];
        aux++;
    }
   }
   return v;
}

#include <stdio.h>

int main()
{
    char texto[50];
    char a = 'a';
    printf("Digite a palavra: ");

    fgets (texto, 50, stdin);

    printf("Digite a letra para remover: ");

    scanf("%c", &a);

    printf("%s", limpaString(&texto, a));


    return 0;
}
