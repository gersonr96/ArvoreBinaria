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

typedef struct NO{
    int numero;
    struct NO *esquerda;
    struct NO *direita;
}no;


void CriarArvore();
void Inserir();
void Remover();
no *MaiorDireita()




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


//Remover Elementos
void Remover(no **Raiz, int numero){
    if(*Raiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
        printf("Numero nao existe na arvore!");
        getch();
        return;
    }
    if(numero < (*Raiz)->numero)
        remover(&(*Raiz)->esquerda, numero);
    else
        if(numero > (*Raiz)->numero)
            remover(&(*Raiz)->direita, numero);
        else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
            no *pAux = *Raiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
            if (((*Raiz)->esquerda == NULL) && ((*Raiz)->direita == NULL)){         // se nao houver filhos...
                free(pAux);
                (*Raiz) = NULL;
            }
            else{     // so tem o filho da direita
                if ((*Raiz)->esquerda == NULL){
                    (*Raiz) = (*Raiz)->direita;
                    pAux->direita = NULL;
                    free(pAux); pAux = NULL;
                }
                else{            //so tem filho da esquerda
                    if ((*Raiz)->direita == NULL){
                        (*Raiz) = (*Raiz)->esquerda;
                        pAux->esquerda = NULL;
                        free(pAux); pAux = NULL;
                    }
                    else{       //Escolhi fazer o maior filho direito da subarvore esquerda.
                        pAux = MaiorDireita(&(*Raiz)->esquerda); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                        pAux->esquerda = (*Raiz)->esquerda;          //        pAux = MenorEsquerda(&(*pRaiz)->direita);
                        pAux->direita = (*Raiz)->direita;
                        (*Raiz)->esquerda = (*Raiz)->direita = NULL;
                        free((*Raiz));  *Raiz = pAux;  pAux = NULL;
                    }
                }
            }
        }

    
}
no *MaiorDireita(no **No){
    if((*No)->direita != NULL)
        return MaiorDireita(&(*No)->direita);
    else{
        no *aux = *No;
        if((*No)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
            *No = (*No)->esquerda;
        else
            *No = NULL;
        return aux;
    }
}

no *MenorEsquerda(no **No){
    if((*No)->esquerda != NULL)
        return MenorEsquerda(&(*No)->esquerda);
    else{
        no *aux = *No;
        if((*No)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
            *No = (*No)->direita;
        else
            *No = NULL;
        return aux;
    }
}


