#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct compu{
    float velocidad ;
    int anio;
    int cantidad;
    char *tipo_cpu ;
};
char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void MostrarListasPcs(struct compu [] , int n);
struct compu Pc_masVieja (struct compu[] , int n);
struct compu Pc_masRapida (struct compu[] , int n);
struct compu crearPCAleatoria();
int generarNumeroAleatorio(int min, int max);


int main(int argc, char const *argv[]){

    // Semilla para la generación de números aleatorios
    srand(time(NULL));

    // Definición del arreglo de PCs
    struct compu pcs[5];

    // Crear 5 PCs aleatorias
    for (int i = 0; i < 5; i++) {
        pcs[i] = crearPCAleatoria();
    }

    // Mostrar la lista de PCs
    MostrarListasPcs(pcs, 5);

    // Mostrar la PC más vieja
    struct compu pcVieja = Pc_masVieja(pcs, 5);
    printf("PC más vieja:\n");
    printf("  Año de fabricación: %d\n", pcVieja.anio);

    // Mostrar la PC con mayor velocidad
    struct compu pcVeloz = Pc_masRapida(pcs, 5);
    printf("PC con mayor velocidad:\n");
    printf("  Velocidad: %.1f GHz\n", pcVeloz.velocidad);

    
    return 0;
}

int generarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}
struct compu crearPCAleatoria() {
    struct compu pc;
    pc.velocidad = generarNumeroAleatorio(1, 3);
    pc.anio = generarNumeroAleatorio(2015, 2024);
    pc.cantidad = generarNumeroAleatorio(1, 8);
    pc.tipo_cpu = tipos[generarNumeroAleatorio(0, 5)];
    return pc;
}
void MostrarListasPcs(struct compu pcs[] , int n){
    int i ;
    printf("\nComputadoras:");
    for ( i = 0; i < n; i++)
    {
        printf("PC %d:\n", i + 1);
        printf("  Velocidad: %.1f GHz\n", pcs[i].velocidad);
        printf("  Año de fabricación: %d\n", pcs[i].anio);
        printf("  Cantidad de núcleos: %d\n", pcs[i].cantidad);
        printf("  Tipo de CPU: %s\n", pcs[i].tipo_cpu);
        printf("\n");

    }
    
}

struct compu Pc_masVieja (struct compu pcs[], int n){
    struct compu masAntigua;
    masAntigua.anio =  pcs[0].anio;

    for (int i = 0; i < n; i++)
    {
        if (masAntigua.anio > pcs[i].anio)
        {
            masAntigua = pcs[i];
        }   
    }
    return masAntigua;
    
}

struct compu Pc_masRapida (struct compu pcs[] , int n){
    struct compu masRapida;
    masRapida.velocidad =  pcs[0].velocidad;

    for (int i = 0; i < n; i++)
    {
        if (masRapida.velocidad < pcs[i].velocidad)
        {
            masRapida = pcs[i];
        }   
    }
    return masRapida;
}