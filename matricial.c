#include <stdio.h>
#include <stdlib.h>
#define IMPOSSIVEL -1
#define   POSSIVEL  0

void imprimeMatriz(int** Matriz, int n, int m){
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            printf("%d ", Matriz[i][j]);
        }
        printf("\n");
    }
}
//considerando n/i numero de linhas e m/j de colunas
int possivelCalcular (int n, int m, int i, int j){
    if(m==i){return POSSIVEL;
    }else{
        return IMPOSSIVEL;
    }
}

void produtomatricial (int** A, int n, int m, int** B, int i, int j){
    int** C;
    C=(int**)malloc(sizeof(int*)*n);
    for (int k = 0; k < n; k++){
        C[k]=(int*)malloc(sizeof(int)*j);
    }
    
    if(possivelCalcular(n, m, i, j)==POSSIVEL){
        for (int k=0; k<n; k++){
            for(int l=0; l<m; l++){
                //mulyiplicar linha de Matriz A por b
                int somaProdutos=0;
                for(int i=0; i<m; i++){
                    somaProdutos= somaProdutos+ A[k][i]*B[i][l];
                }
                C[k][l]=somaProdutos;
            }
        }
        imprimeMatriz(C, n, j);        
    }else{
        printf("Não é possível calcular");
    }
}

int main (){

    //optei por usar o matriz alocadas dinamicamente,
    //visto que assim, não teria que limitar somente a uma dimensão
    int** A;
    int** B;
    A=(int**)malloc(sizeof(int*)*2);
    B=(int**)malloc(sizeof(int*)*3);
    for (int k = 0; k < 2; k++){
        A[k]=(int*)malloc(sizeof(int)*3);
    }
    for (int k = 0; k < 3; k++){
        B[k]=(int*)malloc(sizeof(int)*2);
    }
    A[0][0]=2;
    A[0][1]=3;
    A[0][2]=1;
    
    A[1][0]=0;
    A[1][1]=1;
    A[1][2]=2;

    B[0][0]=2;
    B[0][1]=0;

    B[1][0]=1;
    B[1][1]=-1;

    B[2][0]=3;
    B[2][1]=5;
    produtomatricial(A, 2, 3, B, 3, 2);
}
