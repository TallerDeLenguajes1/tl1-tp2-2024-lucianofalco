#include<stdio.h>
#include<stdlib.h>
#define N 5
#define M 7

int main(int argc, char const *argv[])
{
    int i , j ; 
    int mt[N][M];

    for ( i = 0; i < N; i++)
    {
        for ( i = 0; i < M; i++)
        {
            mt[i][j] = 1 + rand() % 100; 
            printf("%d " , mt[i][j]);
        }
        printf("\n");
        
    }
    
    return 0;
}
