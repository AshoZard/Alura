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
    while (aux->proximo->num < num && aux->proximo != NULL)
    {
      aux = aux->proximo;
    }
    novo->proximo = aux->proximo;  
    aux->proximo = novo;
  }  
  lista->qtdElementos++;
}