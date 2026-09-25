//vetor dinamico é uma estrutura que aloca seus elementos dinamicamente
//pode crescer conforme mais elementos são adicionados
//uso de malloc, free, exit e EXIT_FAILURE

#include<stdlib.h>
#include<stdio.h>

struct vetor_dinamico{
    int *L; //ponteiro para a área de memória onde está o vetor
    int max; //tamanho máximo(atual) do vetor
    int atual; //quantos elementos estão no vetor atualmente
};

typedef struct vetor_dinamico vetor_dinamico;

vetor_dinamico cria_vetor_dinamico(int N){
    vetor_dinamico v;
    if(N <= 0) N = 1;
    v.L = malloc(N * sizeof(int));
    if(v.L = NULL){
        printf("erro de alocacao de memoria\n");
        exit(EXIT_FAILURE);
    }
    v.max = N;
    v.atual = 0;
    return v;
}

void add(vetor_dinamico *v, int x){
    if(v->atual < v-> max){ //se vetor tem espaço livre
        v->L[v->atual] = x; //coloca x na posição atual
        v->atual++; //soma o valor de posições sendo usadas
    } else {
        printf("vetor cheio\n");
    }
}
//funciona, mas não permite que o tamanho máximo seja excedido

void add2(vetor_dinamico*v, int x){
    if(v->atual == v-> max){ //se vetor estiver cheio
        int *A = malloc(2 * v->max * sizeof(int)); //dobra o tamanho do vetor
        if(A = NULL){
            printf("erro de alocacao de memoria\n");
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i < v->max; i++){ //copia vetor L para novo vetor A
            A[i] = v->L[i];
        }
        free(v->L); //libera memoria de L
        v->L = A; //faz o ponteiro v->L apontar para o novo endereço de memória A
        v->max = 2 * v->max; //ajustar tamanho da nova memoria
    }
    v->L[v->atual] = x; //adiciona o elemento x
    v->atual++; //aumenta o numero de posições alocadas

}



