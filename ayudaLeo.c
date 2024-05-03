#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoPilha* PtrNoPilha;
typedef struct NoFila* PtrNoFila;
typedef struct NoLista* PtrNoLista;

typedef struct NoPilha{
  int num;
  PtrNoPilha proximo;
}NoPilha;
typedef struct NoFila{
  int num;
  PtrNoFila proximo;
}NoFila;
typedef struct NoLista{
  int num;
  PtrNoLista proximo;
}NoLista;

typedef struct Pilha{
  PtrNoPilha topo;
  int qtdElementos;
}Pilha;
typedef struct Fila{
  PtrNoFila inicio;
  PtrNoFila fim;
  int qtdElementos;
}Fila;
typedef struct Lista{
  PtrNoLista primeiro;
  int qtdElementos;
}Lista;

void iniciaPilha(Pilha* pilha){
  pilha->qtdElementos = 0;
  pilha->topo = NULL;
}
void iniciaFila(Fila* fila){
  fila->qtdElementos = 0;
  fila->inicio = NULL;
  fila->fim = NULL;
}
void iniciaLista(Lista* lista){
  lista->qtdElementos = 0;
  lista->primeiro = NULL;
}

void inserePilha(Pilha* pilha, int num){
  PtrNoPilha aux = (PtrNoPilha)malloc(sizeof(NoPilha));
  aux->num = num;
  aux->proximo = pilha->topo;
  pilha->topo = aux;
  pilha->qtdElementos++;
}
void insereFila(Fila* fila, int num){
  PtrNoFila aux = (PtrNoFila)malloc(sizeof(NoFila));
  aux->num = num;
  aux->proximo = NULL;
  if (fila->qtdElementos == 0)
  {
    fila->inicio = aux;
    fila->fim = aux;
  }else{
    fila->fim->proximo = aux;
    fila->fim = aux;
  }
  fila->qtdElementos++;
}
void insereLista(Lista* lista, int num){
  PtrNoLista novo = (PtrNoLista)malloc(sizeof(NoLista));
  novo->num = num;
  novo->proximo = NULL;
  if (lista->qtdElementos == 0){
    lista->primeiro = novo;
  }else if (lista->primeiro->num > num){
    novo->proximo = lista->primeiro;
    lista->primeiro = novo;
  }else{
    PtrNoLista aux = lista->primeiro;
    while (aux->proximo != NULL && aux->proximo->num < num)
    {
      aux = aux->proximo;
    }
    novo->proximo = aux->proximo;  
    aux->proximo = novo;
  }  
  lista->qtdElementos++;
}

void imprimePilha(Pilha* pilha){
  PtrNoPilha aux = pilha->topo;
  if (aux == NULL)
  {
    printf("Pilha Vazia!\n");
    return;
  }
  printf("Pilha = [ ");
  
  while (aux != NULL)
  {
    printf("%i ", aux->num);
    aux = aux->proximo;
  }
  printf("]\n");
}
void imprimeFila(Fila* fila){
  PtrNoFila aux = fila->inicio;
  if (aux == NULL)
  {
    printf("Fila Vazia!\n");
    return;
  }
  printf("Fila = [ ");
  
  while (aux != NULL)
  {
    printf("%i ", aux->num);
    aux = aux->proximo;
  }
  printf("]\n");
}

void desempilha(Pilha* pilha){
  PtrNoPilha aux = pilha->topo;
  pilha->topo = pilha->topo->proximo;
  pilha->qtdElementos--;
}
void desenfilera(Fila* fila){
  PtrNoFila aux = fila->inicio;
  fila->inicio = fila->inicio->proximo;
  fila->qtdElementos--;
}

void destroiPilha(Pilha* pilha){
  while (pilha->topo != NULL)
  {
    desempilha(pilha);
  }  
}

int main(void){

  Pilha teste2;
  iniciaPilha(&teste2);
  inserePilha(&teste2, 1);
  inserePilha(&teste2, 2);
  inserePilha(&teste2, 3);
  imprimePilha(&teste2);
  desempilha(&teste2);
  imprimePilha(&teste2);
  desempilha(&teste2);
  imprimePilha(&teste2);

  Fila teste;
  iniciaFila(&teste);
  insereFila(&teste, 1);
  insereFila(&teste, 2);
  insereFila(&teste, 3);
  imprimeFila(&teste);
  desenfilera(&teste);
  imprimeFila(&teste);
  desenfilera(&teste);
  imprimeFila(&teste);

  Lista teste3;
  iniciaLista(&teste3);
  insereLista(&teste3, 1);
  insereLista(&teste3, 2);
  insereLista(&teste3, 3);
  // imprimeLista(&teste3);
  // desenfilera(&teste3);
  // imprimeLista(&teste3);
  // desenfilera(&teste3);
  // imprimeLista(&teste3);

  return 0;
}