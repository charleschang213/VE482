#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum __bool__{FALSE,TRUE} bool;

bool banker(int n,int r,int *E,int **C,int **R);

int main(){
    int n = 5;
    int r = 4;
    int E[4] = {6,3,4,2};
    int **C = malloc(n*sizeof(int));
    int **R = malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        C[i] = malloc(r*sizeof(int));
        R[i] = malloc(r*sizeof(int));
        for (int j=0;j<r;j++) {
            C[i][j]=R[i][j]=1;
        }
    }
    bool safe = banker(n,r,E,C,R);
    for (int i=0;i<n;i++){
        free(C[i]);
        free(R[i]);
    }
    free(C);free(R);
    if (safe==TRUE) printf("safe\n");
    else printf("unsafe\n");
}

bool banker(int n,int r,int *E,int **C,int **R){
    int *A = malloc(r*sizeof(int));
    memcpy(A,E,r*sizeof(int));
    bool *complete = malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        complete[i] = FALSE;
        for (int j=0;j<r;j++) A[j] = A[j]-C[i][j];
    }
    for (int i=0;i<n;i++){
        bool available = FALSE;
        for (int j=0;j<n;j++){
            if (complete[j]==TRUE) continue;
            available = TRUE;
            for (int k=0;k<r;k++)
                if (R[j][k]>A[k]){
                    available = FALSE;
                    break; 
                }
            if (available==TRUE){
                complete[j] = TRUE;
                for (int k=0;k<r;k++)A[k]+=C[j][k];
                break;
            }
        }
        if (available==FALSE) {
            free(A);free(complete);
            return FALSE;
        }
    }
    free(A);free(complete);
    return TRUE;
}
