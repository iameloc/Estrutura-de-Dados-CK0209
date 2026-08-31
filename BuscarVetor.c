#include <stdio.h>
#include <stdlib.h>


int main(){
    int A[5] = {10,4,5,8,12};
    int K = 5;
    int ans = -1;
    int find = 0;
    for(int i = 0; i<5; i++){
        if(A[i] == K){
            ans = i;break;
        }
    }
    printf("%d ", ans);
}

//algoritmo percorre um vetor A em busca de um dado elemento K
//se K estiver em A, ans recebe o valor do índice de K
//caso contrario, ans recebe o valor -1

//complexidade O(n), complexidade horrorosa segundo o professor