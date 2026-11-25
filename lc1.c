#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no *p_no;

struct no{
    char atomico;
    int valorLogico;
    p_no esq, dir;
};

p_no criaAtomico(char nome, int valor){
    p_no novo = malloc(sizeof(no));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->valorLogico = valor;
    novo->atomico = nome;
    return novo;
}

p_no criaOp(char nome, p_no esq, p_no dir){
    p_no op = malloc(sizeof(no));
    op->esq = esq;
    op->dir = dir;
    op->atomico = nome;
    op->valorLogico = -1;
    return op;
}

p_no analisar(p_no no){
    if(no == NULL){
        return NULL;
    }
    if(no->esq == NULL || no->dir == NULL){
        return no->valorLogico;
    }

    int p = analisar(no->esq);
    int q = analisar(no->dir);

    switch(no){
        case '!':
            return !(p);
        case '&':
            return (p &&  q);
        case '|':
            return (p ||q);
        case '>':
            return ((!p)||q);              //condicional
        case '=':
            return ((p && q) || ((!p) && (!q)) );          //bicondicional
        default: return NULL;
    }
}

void imprimir(p_no no){
    if(no == NULL){
        return;
    }
    if(no->esq ==NULL && no->dir ==NULL){
        printf("%c ", no->atomico);
        return;
    }

    if (no->atomico == '~') {
        printf("(~");
        imprimir(no->esq);
        printf(")");
        return;
    }

    printf("(");
    imprimir(no->esq);
    printf(" %c ", raiz->atomico);
    imprimir(no->dir);
    printf(")");
}

void lixo(p_no){
    if (no == NULL) {
        return;
    }
    lixo(no->esq);
    lixo(no->dir);
    free(no);
}



int main(){
    int i=0;
    //Fórmula tem tamanho dinâmico
    size_t tam = 100;
    char *formula = malloc((tam+1)* sizeof(char));

    if(formula == NULL){
        return 0;
    }

    do{
        scanf("%c", formula[i]);

        if(formula[i] == '~'){
            char dir, esq;
            for(int j =0; j < tam; j++){
                if(formula[j+1] == ')'){
                    
                }
            }
            i++;
            criaAtomico(formula[i], 0);
        }else if((formula[i] >= 65 && formula[i] <= 165) || (formula[i] >= 30 && formula[i] <=39))
        
        i++;
    }while(formula != '\0');

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
