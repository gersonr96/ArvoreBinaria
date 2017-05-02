//
//  main.c
//  AnaliseArvoreBinaria
//
//  Created by Gerson Rodrigo on 02/05/17.
//  Copyright © 2017 Gerson Rodrigo. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#define TAM 50

void CriarArvore();
void Inserir();
void Remover();


typedef struct NO{
    int numero;
    struct NO *esquerda;
    struct NO *direita;
}no;



int main(int argc, const char * argv[]) {
    
    no *Raiz;
    double tempo;
    CriarArvore(&Raiz);
    
    
    clock_t inicial, final;
    inicial = clock();
    for(int i = 0; i < TAM; i ++){
        
        Inserir(&Raiz, i);
        
    }
    final = clock();
    tempo = ((double)(final - inicial)/CLOCKS_PER_SEC);
    
    
    
    
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}





//Criar Arvore Binaria
void CriarArvore(no *Raiz){
    Raiz = NULL;
}

//Inserir os dados
void Inserir(no **Raiz, int numero){
    

        if (*Raiz == NULL){
            *Raiz = (no*) malloc(sizeof(int));
            (*Raiz)->direita = NULL;
            (*Raiz)->esquerda = NULL;
            (*Raiz)->numero = numero;
        }else{
            
            if (numero < (*Raiz)->numero)
                Inserir(&(*Raiz)->esquerda, numero);
            if (numero > (*Raiz)->numero)
                Inserir(&(*Raiz)->direita, numero);
                        
            
        }

}

