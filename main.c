#include <stdio.h>
#include <stdlib.h>



struct No{
  int valor;
  struct No *proximo;
};

void insereOrdenado(struct No * cabeca, int novoValor){
  
  struct No * novoNo = (struct No *) malloc(sizeof(struct No));
  novoNo->valor = novoValor;

  if(cabeca->proximo == NULL){//lista vazia
    cabeca->proximo = novoNo;
  }
  else{
    struct No * noAuxiliar = cabeca->proximo;
    if(noAuxiliar->valor > novoValor){//menor que primeiro
      novoNo->proximo = noAuxiliar;
      cabeca->proximo = novoNo;
      return;
    }
    while(noAuxiliar->proximo != NULL){
       if(noAuxiliar->proximo->valor > novoValor){
         printf("NoAuxiliar: %d | novoValor: %d\n", noAuxiliar->proximo->valor, novoValor);
         novoNo->proximo = noAuxiliar->proximo;
         noAuxiliar->proximo = novoNo;
         return;
       }
       noAuxiliar = noAuxiliar->proximo;
    }
    noAuxiliar->proximo = novoNo;
  }

}

void getElemento(struct No * cabeca, int indice){
  int aux=0;
  struct No *noAuxiliar = cabeca->proximo;
  while(noAuxiliar != NULL){
    if(indice == aux){
      printf("Valor Recuperado: %d \n", noAuxiliar->valor);
      aux++;
    }else{
      aux++;
    }
    noAuxiliar = noAuxiliar->proximo;
  }
}

void imprimeLista(struct No * cabeca){
  struct No *noAuxiliar = cabeca->proximo;
  while(noAuxiliar != NULL){
    printf("%d ", noAuxiliar->valor);
    noAuxiliar = noAuxiliar->proximo;
  }
}

int main(void) {
  struct No * cabeca = (struct No *) malloc(sizeof(struct No));
  insereOrdenado(cabeca, 5);
  insereOrdenado(cabeca, 3);
  insereOrdenado(cabeca, 2);
  insereOrdenado(cabeca, 1);
  insereOrdenado(cabeca, 0);
  insereOrdenado(cabeca, 7);
  insereOrdenado(cabeca, 9);
  insereOrdenado(cabeca, 4);
  insereOrdenado(cabeca, 6);
  insereOrdenado(cabeca, 8);
  getElemento(cabeca,6);
  imprimeLista(cabeca);
  return 0;
}