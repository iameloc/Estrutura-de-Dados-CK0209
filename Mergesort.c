#include <stdlib.h>
#include <stdio.h>

void Merge(int A[],int p,int q,int r){
    //entrada: A[p,...,q] e A[q+1,...,r] ordenados
    //saida: A[p,...,r] ordenado

    //criando vetores esquerda(E) e direita(D)
    int E[q-p+1];
    int D[r-q];

    //copiando os respectivos elementos de A para cada metade
    for(int i = 0; i<(q-p+1); i++){
        E[i] = A[p+i];
    }
    for(int i = 0; i<(r-q); i++){
        D[i] = A[q+1+i];
    }

    //criando dedos/ponteiros para E e D
    int e = 0; int d = 0;
    int k = p;

    //ideia principal
    while(e<(q-p+1) && d<(r-q)){
        if(E[e]<=D[d]){
            A[k] = E[e]; e++;
        }else{
            A[k] = D[d]; d++;
        }
        k++;
    }

    //caso D tenha acabado primeiro, copiamos o resto dos elementos de E
    while(e<(q-p+1)){
        A[k] = E[e]; e++; k++;
    }

    //raciocínio análogo para se E acabar primeiro
    while(d<(r-q)){
        A[k] = D[d]; d++; k++;
    }
}

void MergeSort(int A[],int p,int r){
    if(p<r){
        int q = (p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}
