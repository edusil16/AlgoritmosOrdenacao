/*
FEUC - FUNDAÇÃO EDUCACIONAL UNIFICADA CAMPOGRANDENSE
FIC - FACULDADES INTEGRADAS CAMPO - GRANDENSES

TRABALHO DESENVOLVIDO PARA TESTES DE DESEMPENHO DOS ALGORITMOS DE PESQUISA E ORDENAÇÃO,
TESTADO NO MODO ALEATÓRIO, CRESCENTE & DECRESCENTE COM 100, 1000, 10000 NÚMEROS.

ALUNOS: EDUARDO SILVA DOS SANTOS
		WELLINGTON SOUZA

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define padrao 3

struct numero{
	int numero;
};

void cria(int[]);
void ler(int[]);
void selectionSort(int[],int);
void insertionSort(int[],int);
void bubbleSort(int[],int);
void quickSort(int[],int,int);
void shellSort(int[],int);
void mergeSort(int[],int);
void heapSort(int[],int);
void imprimevetor(int[],int);

int troca=0, comparacao=0;
int vetor[padrao];


int main(){
	setlocale(LC_ALL, "Portuguese");
	int d=0,e=0;
	int escolha;
	int op;

	do{
	
	printf("\n\n Escolha uma Opção:");
	printf("\n 1. Selection Sort \n 2. Insertion Sort \n 3. Bubble Sort \n 4. Quick Sort \n 5. Shell Sort \n 6. Merge Sort \n 7. Heap Sort \n 0. Exibir Numeros ......  ");
    scanf("%d",&escolha);
	
	printf("\n\n");
	ler(vetor);
	
	switch(escolha){
		case 1:
		        selectionSort(vetor,padrao);
				imprimevetor(vetor,padrao);
				break;
 		case 2: insertionSort(vetor,padrao);
		 		imprimevetor(vetor,padrao);
				break;
		case 3: bubbleSort(vetor,padrao);
				imprimevetor(vetor,padrao);
				break;
		case 4: quickSort(vetor, 0, padrao-1);
				imprimevetor(vetor,padrao);
				break;
		case 5: shellSort(vetor,padrao);
				imprimevetor(vetor,padrao);
				break;
		case 6: mergeSort(vetor,padrao);
				imprimevetor(vetor,padrao);
				break;
		case 7: heapSort(vetor,padrao);
				imprimevetor(vetor,padrao);
				break;
		default: break; 	
}} while (op==0);
	
		return 0;
}



void ler(int vetor[]){
	FILE *arq;
	struct numero n[padrao];
	int i;

	arq = fopen("ArqGrav.txt","r");
	
	for(i=0;i<padrao;i++){
		fscanf(arq,"%d",&n[i].numero);
	}
	
	fclose(arq);
	
	for(i=0;i<padrao;i++){
		printf("%d\n",n[i].numero);
		vetor[i]=n[i].numero;
	}
}

void imprimevetor(int vetor[], int tam){
	int i;
	
	for(i=0;i<padrao;i++){
		printf("%d, ",vetor[i]);
	}

	
	printf("\n\nComparacoes: %d\nTrocas: %d",comparacao,troca);
}

void selectionSort(int vetor[], int tam){
	int i, j, min, aux;
	
	for (i = 0; i < (tam-1); i++){
		min = i;
		
		for (j = (i+1); j < tam; j++){
			comparacao++;
			if (vetor[j] < vetor[min]){
				min = j;
			}
		}
		
		if (i != min){
			aux = vetor[i];
			vetor[i] = vetor[min];
			vetor[min] = aux;
			troca++;
		}
	}
}

void insertionSort(int vetor[], int tam){
	 int j,i,key;
	 
	 for(j = 1; j < tam; j++){
	 		
		key = vetor[j];
		i = j - 1;
		comparacao++;
		while(i >= 0 && vetor[i] > key){
			comparacao++;
			vetor[i + 1] = vetor[i];
			i = i - 1;
		troca++;
		 }
	 	vetor[i + 1] = key;
	 	
	 	
	 	
	 }

}

void bubbleSort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {

        for (j = 0; j < n - 1; j++) { 
               comparacao++;      
            if (vetor[j] > vetor[j + 1]){  
                aux=vetor[j];
                vetor[j]=vetor[j + 1];
                vetor[j+1] = aux;
                troca++; 
            }
        }
    } 
}

void quickSort(int vetor[], int esquerda, int direita) {
 int i, j, x, y;
 i = esquerda;
 j = direita;
 x = vetor[(esquerda + direita) / 2];
 while(i <= j) 
 { comparacao++;
  while(vetor[i] < x && i < direita)
 { i++; }
 while(vetor[j] > x && j > esquerda)
 { j--; }
 if(i <= j) 
 { y = vetor[i];
 vetor[i] = vetor[j];
 vetor[j] = y;
 i++;
 j--;
	troca++;
 }
 }
 if(j > esquerda) { quickSort(vetor, esquerda, j); }
 if(i < direita) { quickSort(vetor, i, direita); }
}

void shellSort(int *vetor, int tam) {
	 int i , j , value;
	 int gap = 1;
	 
	 while (gap < tam){
		gap = 3*gap+1; 
	}
	 while (gap > 1) {
		 gap /= 3;
		 
		 for(i = gap; i < tam; i++) { 
			 value = vetor[i];
			 j = i - gap;
			 	 comparacao++;
			 while (j >= 0 && value < vetor[j]){ 
				 vetor[j + gap] = vetor[j];
				 j -= gap;
				 
			 }
			 vetor[j + gap] = value;
			troca++; 
		 }
	 }
}

void merge(int vetor[], int tam) {
	 int mid;
	 int i, j, k;
	 int* tmp;
	 tmp = (int*) malloc(tam * sizeof(int));
	 
	 
	 if (tmp == NULL){ 
	 	exit(1);
	 }
	 
	 mid = tam / 2;
	 i = 0;
	 j = mid;
	 k = 0;
	 
	 
	 while (i < mid && j < tam){ 
	 	 
		 if (vetor[i] <= vetor[j]){ 
		 	tmp[k] = vetor[i++]; 
		 }
		 else{
			 tmp[k] = vetor[j++];
		 }
		 
	 	 ++k;
	 }
	 
	 
	 if (i == mid) {
	 	while (j < tam) { comparacao++;
		 	tmp[k++] = vetor[j++];
		 }
	 } else {
	 	while (i < mid) {
		 	tmp[k++] = vetor[i++];
		 }
	 }
	 
	 for (i = 0; i < tam; ++i) { troca++;
	 	vetor[i] = tmp[i];
	 }
	 
	 free(tmp); 
}


void mergeSort(int vetor[], int tam) {
	 int mid;
	 
	 if (tam > 1) {
		 mid = tam / 2;
		 mergeSort(vetor, mid);
		 mergeSort(vetor + mid, tam - mid);
		 merge(vetor, tam);
 	}
}


void heapSort(int vetor[], int tam){
	 int i = tam/2, pai, filho, t, tt=tam-1;
	 
	for (;;){ troca++;
		if (i > 0)
		{ i--;
		t = vetor[i]; }
	 
	 
	else{
		tam--;
		
		if (tam == 0) {
			
		if (vetor[tt-1]>vetor[tt]){ 
			t=vetor[tt];
			vetor[tt]=vetor[tt-1];
			vetor[tt-1]=t;
		}
		return;
		
		}
		t = vetor[tam];
		vetor[tam] = vetor[0];
	}
	
	 pai = i;
	 filho = i*2; 
	while (filho < tam){ comparacao++;
		if ((filho + 1 < tam) && (vetor[filho + 1] > vetor[filho])){
			filho++;
		}
		
		if (vetor[filho] > t){
			vetor[pai] = vetor[filho];
			pai = filho;
		 	filho = pai*2 + 1;
		}
		
		else{
			break;
		}
	} 
	
	vetor[pai] = t;
	
	}
}

void ler(int vetor){
	FILE *arq;
	struct numero num[padrao];
	int i;

	arq = fopen("numeros.txt","r");
	
	for(i=0;i<padrao;i++){
		fscanf(arq,"%d",&num[i].numero);
	}
	
	fclose(arq);
	
	for(i=0;i<padrao;i++){
		printf("%d\n",num[i].numero);
		vetor=num[i].numero;
	}
}
