// exemplos de operações simples usando ponteiros para alterar valores diretamente na memória.
#include <stdlib.h>
#include <stdio.h>

void dobro(int a, int *x){ //parametros: inteiro a  , valor inteiro acessado pelo ponteiro x
    *x = 2*a; //valor acessado pelo ponteiro x recebe o dobro de a
}

void troca(int *pa, int *pb){ //parametros: valor inteiro acessado pelo ponteiro pa , valor inteiro acessado pelo ponteiro pb
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

//obs: &a -> endereço de a ; ponteiro apontando para variável a
//     *a -> guarda o valor do endereço a

//Retornando mais de um valor de uma função

//alterando valores diretamente na memória
void segundo_maior(int L[], int N, int *maior, int *smaior){
    *maior = *smaior = L[0];

    for(int i = 1; i<N; i++){
        if(L[i] > *maior){
            *smaior = *maior;
            *maior = L[i];
        } else if (L[i] > *smaior){
            *smaior = L[i];
        }
    }
}

//usando struct
struct Resultado{
    int maior;
    int smaior;
};

typedef struct Resultado Resultado; //evitar ficar digitando struct resultado toda hora; simplificar o trabalho

Resultado segundo_maior2(int L[], int N){
    Resultado M;
    M.maior = M.smaior = L[0];
    
    for(int i = 1; i<N; i++){
        if(L[i] > M.maior){
            M.smaior = M.maior;
            M.maior = L[i];
        } else if(L[i] > M.smaior){
            M.smaior = L[i];
        }
    }

    return M;
}


//struct passada por ponteiro
void segundo_maior3(int L[], int N, Resultado *r){
    r->maior = L[0]; //mesmo que (*r).maior, acessa a struct r e pega o maior
    r->smaior = L[0];

    for(int i = 1; i<N; i++){
        if(L[i] > r->maior){
            r->smaior = r->maior;
            r->maior = L[i];
        } else if(L[i] > r->smaior){
            r->smaior = L[i];
        }
    }
}// nessa versão, nenhuma cópia da variável  M é criada
// no entando, cada r-> (operação de acesso) custa um pouco