/*
FEUC - FUNDAÇÃO EDUCACIONAL UNIFICADA CAMPOGRANDENSE
FIC - FACULDADES INTEGRADAS CAMPO - GRANDENSES

TRABALHO DESENVOLVIDO PARA TESTES DE DESEMPENHO DOS ALGORITMOS DE PESQUISA E ORDENAÇÃO,
TESTADO NO MODO ALEATÓRIO, CRESCENTE, DECRESCENTE COM 100, 1000, 10000 NÚMEROS.

ALUNOS: EDUARDO SILVA DOS SANTOS
		WELLINGTON SOUZA

*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define padrao 10

int main(void)
{
FILE *arq;
arq = fopen("ArqGrav.txt", "wt"); // Cria um arquivo texto para gravação
	int i, result;
	 
if (arq == NULL) // Se não conseguiu criar
{ printf("Problemas na CRIACAO do arquivo\n");
 
}
for (i=0; i<padrao; i++) 
	result = fprintf(arq,"%d\n",i);

if (result == EOF)
 printf("Erro na Gravacao\n");
fclose(arq);
}
