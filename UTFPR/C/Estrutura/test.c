#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> //0/1 false/true


typedef struct NoFila* PtrNoFila;

typedef struct NoFila{
	int chave;
	PtrNoFila proximo;
} NoFila;

typedef struct{
	PtrNoFila inicio;
	PtrNoFila fim;
	int qtdElementos;
} FilaDinamica;

void iniciaFilaDinamica(FilaDinamica *f){
	f->inicio = NULL;
	f->fim = NULL;
	f->qtdElementos = 0;
}

bool estaVaziaFilaDinamica(FilaDinamica *f){
	return(f->inicio == NULL);
}

int tamanhoFilaDinamica(FilaDinamica *f){
	return f->qtdElementos;
}

void inserirFilaDinamica(FilaDinamica *f, int valor){
	PtrNoFila aux = malloc(sizeof(NoFila));
	aux->chave = valor;
	aux->proximo = NULL;
	if(estaVaziaFilaDinamica(f)){
		f->inicio = aux;
	}
	else{
		f->fim->proximo = aux;
	}
	f->fim = aux;
	f->qtdElementos++;
}

void removerFilaDinamica(FilaDinamica *f){
	if(!estaVaziaFilaDinamica(f)){
		PtrNoFila aux;
		aux = f->inicio;
		f->inicio = f->inicio->proximo;
		free(aux);
		f->qtdElementos--;
	}
	else{
		printf("Fila Vazia!\n");
		}
}

int inicioFilaDinamica(FilaDinamica *f){
	int ret = -1;
	if(!estaVaziaFilaDinamica(f)){
		ret = f->inicio->chave;
	}
	return ret;
}

int fimFilaDinamica(FilaDinamica *f){
	int ret = -1;
	if(!estaVaziaFilaDinamica(f)){
		ret = f->fim->chave;
	}
	return ret;
}

void imprimirFilaDinamica(FilaDinamica *f){
	printf("\nFila = [");
	PtrNoFila aux;
	for(aux=f->inicio;aux!=NULL;aux=aux->proximo){
		printf("%d ", aux->chave);
	}
	printf("]\n");
}

void quantidadeAvioes(FilaDinamica *f){
	printf("\nAgora ha %i avioes na fila!", tamanhoFilaDinamica(f));
}

void autorizaDecolagem(FilaDinamica *f){
	printf("\nAutorizada a decolagem do aviao: %i.", f->inicio->chave);
	removerFilaDinamica(f);
}

void adicionaAviao(FilaDinamica *f, int aviao){
	printf("\nO aviao '%i' esta, agora, na lista de espera para decolagem.", aviao);
	inserirFilaDinamica(f, aviao);
}

void listaAvioes(FilaDinamica *f){
	if (estaVaziaFilaDinamica(f))
	{
		printf("\nPista Livre, fila vazia!");
	}else{
		imprimirFilaDinamica(f);		
	}
}

void listaCaracteristicas(FilaDinamica *f){
	printf("\nO primeiro aviao da fila e o '%i'", inicioFilaDinamica(f));
}

int main(){
	FilaDinamica *filaAvioes = malloc(sizeof(FilaDinamica));
	iniciaFilaDinamica(filaAvioes);

	adicionaAviao(filaAvioes, 1);
	adicionaAviao(filaAvioes, 2);
	adicionaAviao(filaAvioes, 3);
	adicionaAviao(filaAvioes, 4);

	listaAvioes(filaAvioes);

	autorizaDecolagem(filaAvioes);

	listaCaracteristicas(filaAvioes);

	quantidadeAvioes(filaAvioes);
	return 0;
}