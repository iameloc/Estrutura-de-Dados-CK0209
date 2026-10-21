#include <stdlib.h>
#include <stdio.h>

void InsertionSort(int A[], int n){
    for(int j = 1; j<n; j++){
        int x = A[j];
        int i = j-1;
        while(i>=1 && A[i]>x){
            A[i+1] = A[i]; i--;
        }
        A[i+1] = x;
    }
}