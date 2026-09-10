#include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int A[], int n, int K){
    int i = 0; int f = n;
    while(i<=f){
        int m = (i+f)/2;
        if(A[m]==K){
            return m;
        }
        else if(A[m]>K){
            f = m-1;
        }
        else{
            i = m+1;
        }
    }
    return -1;
}

int main(){
    int vetor[] = {1,23,46,77,80,81,85,90,100,120};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    int alvo;

    scanf("%d", &alvo);
    int resultado = BuscaBinaria(vetor,tamanho,alvo);

    printf("%d",resultado);
}

//vetor deve estar ordenado
//dado um vetor A de tamanho n, buscamos por um elemento K
//caso K esteja no vetor, retorna o indice do elemento K
//caso não esteja, retorna -1

//complexidade O(lg n), muito boa complexidade

//fazer testes e, a cada teste, descartar metade dos elementos