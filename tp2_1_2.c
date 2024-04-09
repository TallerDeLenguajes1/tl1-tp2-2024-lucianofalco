//Nuevo archivo creado en branch opcion2
#include<stdio.h>
#include<stdlib.h>

#define N 20

int main(int argc, char const *argv[])
{    
    int i ; 
    double vt[N];
    double *pvt ; 
    pvt = &vt[0] ; 
    for ( i = 0; i < N; i++)
    {
        *(pvt + i) = 1 + rand()%100 ; 
        printf("%f " , vt[i]);
    }
    
    return 0;
}
