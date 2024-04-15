#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> //0/1 false/true


typedef struct NoPilha* PtrNoPilha;
typedef struct NoPilhaStr* PtrNoPilhaStr;

struct NoPilha{
	int elemento;
	PtrNoPilha proximo;
}NoPilha;

struct NoPilhaStr{
	char letra;
	PtrNoPilhaStr proximo;
}NoPilhaStr;

typedef struct{
	PtrNoPilha topo;
	int qtde;
}PilhaDinamica;

typedef struct{
	PtrNoPilhaStr topo;
	int qtde;
}PilhaDinamicaStr;

void iniciaPilhaDinamica(PilhaDinamica *p){
	p->qtde = 0;
	p->topo = NULL;	
}

void iniciaPilhaDinamicaStr(PilhaDinamicaStr *p){
	p->qtde = 0;
	p->topo = NULL;	
}

bool estaVaziaPilhaDinamica(PilhaDinamica *p){
	return(p->topo == NULL);
}

bool estaVaziaPilhaDinamicaStr(PilhaDinamicaStr *p){
	return(p->topo == NULL);
}

int tamanhoPilhaDinamica(PilhaDinamica *p){
	return(p->qtde);
}

void imprimirPilhaDinamica(PilhaDinamica *p){
	printf("Pilha = [");
	PtrNoPilha aux;
	for(aux =p->topo; aux != NULL; aux =  aux->proximo){
		printf("%d ", aux->elemento);
	}
	printf(" ]\n");
}

void inserirPilhaDinamica(PilhaDinamica *p, int num){
	PtrNoPilha aux = malloc(sizeof(NoPilha));
	aux->elemento = num;
	aux->proximo = p->topo;
	p->topo = aux;
	p->qtde++;
}

void inserirPilhaDinamicaStr(PilhaDinamicaStr *p, char letter){
	PtrNoPilhaStr aux = malloc(sizeof(NoPilhaStr));
	aux->letra = letter;
	aux->proximo = p->topo;
	p->topo = aux;
	p->qtde++;
}

void removerPilhaDinamica(PilhaDinamica *p){
	if(!estaVaziaPilhaDinamica(p)){
		PtrNoPilha aux;
		aux = p->topo;
		p->topo = p->topo->proximo;
		free(aux);
		p->qtde--;		
	}
	else{
		printf("Warning: pilha esta vazia!\n");
	}
}

void removerPilhaDinamicaStr(PilhaDinamicaStr *p){
	if(!estaVaziaPilhaDinamicaStr(p)){
		PtrNoPilhaStr aux;
		aux = p->topo;
		p->topo = p->topo->proximo;
		free(aux);
		p->qtde--;		
	}
	else{
		printf("Warning: pilha esta vazia!\n");
	}
}

void invertePilhaDinamica(PilhaDinamica *p){
    int tamanho = p->qtde;
    int vetor[tamanho];
  if (tamanho > 1)
  {
    for (int i = 0; i < tamanho; i++)
    {
      vetor[i] = p->topo->elemento;
      removerPilhaDinamica(p);
    }
    for (int i = 0; i < tamanho; i++)
    {
      inserirPilhaDinamica(p, vetor[i]);
    }
  }  
}

//Tarefa para voc�s:
//implementar a fun��o destruir
//pesquisar ou retornar o elemento do topo
typedef struct NoFila* PtrNoFila;

typedef struct NoFila{
	int chave;
	//int idade;
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
	printf("\nFila = [ ");
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
	
	
  /*Exercício 2
  
  FilaDinamica fila;
	iniciaFilaDinamica(&fila);
	inserirFilaDinamica(&fila, 6);
	inserirFilaDinamica(&fila, 10);
	inserirFilaDinamica(&fila, 2);
	inserirFilaDinamica(&fila, 7);
  
	imprimirFilaDinamica(&fila);
  
  PilhaDinamica pilha;
	iniciaPilhaDinamica(&pilha);

  for (;fila.qtdElementos != 0;)
  {
    inserirPilhaDinamica(&pilha, fila.inicio->chave);
    removerFilaDinamica(&fila);
  }
  imprimirPilhaDinamica(&pilha);
  
  for (;pilha.qtde != 0;)
  {
    inserirFilaDinamica(&fila, pilha.topo->elemento);
    removerPilhaDinamica(&pilha);
  }
  imprimirFilaDinamica(&fila);
	
  */


 	/*
	Exercício 3:

  printf("Escreva ai meu jovem...\n");
  char string[100];
  scanf("%s", string);
	PilhaDinamicaStr *pilhastr = malloc(sizeof(PilhaDinamicaStr));
	iniciaPilhaDinamicaStr(pilhastr);
  
  for (int i = 0; string[i] != '\0'; i++)
  {
    inserirPilhaDinamicaStr(pilhastr, string[i]);
  }
  
	int verificador = 1;
	int contador = 0;

	while (pilhastr->qtde != 0)
	{
    if (string[contador] != pilhastr->topo->letra)
    {
      verificador = 0;
    }
    
		string[contador] = pilhastr->topo->letra;	
		removerPilhaDinamicaStr(pilhastr);
		contador++;
	}
	printf("\nReverso: %s\n\n", string);
	if (verificador == 1)
	{
		printf("E um palindromo! :D");
	}else if (verificador == 0)
	{
		printf("Nao e um palindromo :c");
	}
*/

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