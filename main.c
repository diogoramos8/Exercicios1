#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct no{
    int dado;
    struct no* proximo;

}no_t;

void obliterar(no_t** inicio) {
    no_t* atual = *inicio;
    no_t* proximo = NULL;   
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *inicio= NULL;
}
void add(no_t* *inicio, int dado){
    no_t* novo =(no_t*) malloc(sizeof(no_t));
    novo->dado = dado;
    novo->proximo = *inicio;
    *inicio = novo;

}
bool remover(no_t* *inicio, int elemento){
    no_t* atual = *inicio;
    no_t* anterior = NULL;
    while(atual != NULL){
        if(atual->dado == elemento){
            if(anterior == NULL){
                //para o primeiro elemento da lista
                *inicio = atual->proximo;
            }else {
                //para os demais elementos
                anterior->proximo = atual->proximo;
            }
            free(atual);
            return true;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return false;
}


int main() {
//    no_t primeiro;
//    no_t segundo;
//    no_t terceiro;
//
//    primeiro.dado=1;
//    primeiro.proximo=NULL;
//
//    segundo.dado=2;
//    segundo.proximo=NULL;
//
//    terceiro.dado=3;
//    terceiro.proximo=NULL;
//
//    primeiro.proximo = &segundo;
//
//    segundo.proximo=&terceiro;

    no_t *inicio = NULL;
    add(&inicio, 1);
    add(&inicio, 2);
    add(&inicio, 3);
    add(&inicio, 4);
    remover(&inicio, 4);
    while(inicio != NULL){
        printf("%d\n", inicio->dado);
        inicio= inicio->proximo;
    }
    obliterar(&inicio);
    return 0;
}
