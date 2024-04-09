#include<stdio.h>
#include<stdlib.h>

#define N 20
int i ; 
double vt[N];

int main(int argc, char const *argv[])
{    
    for ( i = 0; i < N; i++)
    {
        vt[i] = 1 + rand()%100 ; 
        printf("%f " , vt[i]);
    }
    
    return 0;
}
