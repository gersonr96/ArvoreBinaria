//
//  main.c
//  AnaliseArvoreBinaria
//
//  Created by Gerson Rodrigo on 02/05/17.
//  Copyright © 2017 Gerson Rodrigo. All rights reserved.
//

#include <stdio.h>

typedef struct NO{
    int numero;
    struct NO *esquerda;
    struct NO *direita;
}no;



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}




//Criar Arvore Binaria
void CriarArvore(no *Raiz){
    Raiz = NULL;
}

//Inserir os dados
void Inserir(no **Raiz, int V[], int TAM){
    
    for(int i = 0; i < TAM; i ++){
        if (*Raiz == NULL){
            *Raiz = (no*) malloc(sizeof(int));
            
            
        }
    }
}
