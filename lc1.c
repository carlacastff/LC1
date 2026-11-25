#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no *p_no;

struct no{
    char dado;
    p_no esq, dir;
};

p_no criar(char dado, p_no dir, p_no esq){
    p_no novo = malloc(sizeof(struct no));
    if(){
        
    }
    novo->esq = NULL;
    novo->dir = NULL;
    novo->dado = dado;
}


int main(){
    //Fórmula tem tamanho dinâmico
    size_t tam = 100;
    char *formula = malloc((tam+1)* sizeof(char));

    if(formula == NULL){
        return 0;
    }

    fgets(formula, tam+1, stdin) ;

    size_t t = strlen(formula);
        
    //Realocação
    char *temp = (char *)realloc(formula, (t+1) * sizeof(char));
    if(temp == NULL){
        free(formula);
        return 0;
    }

    formula = temp;
    
    free(formula);
    formula = NULL;
    return 0;
}