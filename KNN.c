//librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 20 //Total de puntos
#define K 1 //Numero de vecinos a considerar

// Definición de la estructura para almacenar los puntos
typedef struct punto{
    float x;
    float y;
    float z;
    char clase[45];
} punto;

// Definición de la estructura para almacenar los vecinos
typedef struct vecino{
    float distancia;
    int indice;

}vecino;

// Prototipos de funciones
// Funciones para calcular la distancia euclídea y comparar distancias
// Función para calcular la distancia euclídea entre dos puntos
// Función para clasificar un nuevo punto usando el algoritmo KNN
float distanciaEuclidea(punto p1, punto p2);
int comparar(const void *a, const void *b);
char* knn(punto dataset[], punto nuevoPunto);

int main(){

    punto dataset[20] = {
    {1.0, 2.1, 0.5, "A"}, {2.3, 3.1, 1.2, "A"}, {1.5, 2.6, 0.8, "A"}, {3.0, 3.0, 1.0, "A"}, {2.0, 1.9, 0.9, "A"},
    {6.0, 5.5, 3.2, "B"}, {7.3, 6.1, 4.0, "B"}, {6.5, 5.6, 3.1, "B"}, {8.0, 6.0, 4.3, "B"}, {7.0, 5.9, 3.7, "B"},
    {1.8, 2.2, 1.0, "A"}, {2.1, 2.9, 0.7, "A"}, {3.2, 1.5, 1.1, "A"}, {1.3, 2.7, 0.4, "A"}, {2.5, 2.0, 1.3, "A"},
    {6.8, 6.2, 3.6, "B"}, {7.1, 6.9, 3.9, "B"}, {8.2, 5.5, 4.4, "B"}, {6.3, 5.7, 3.3, "B"}, {7.5, 6.0, 4.1, "B"}
    };
    

    punto nuevoPunto = {5.5, 5.5, 5.5, ""}; // Punto a clasificar
    char* clase = knn(dataset, N, nuevoPunto, K);
    printf("La clase del nuevo punto es: %s\n", clase);


    return 0;
}

float distanciaEuclidea(punto p1, punto p2){
    return sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2) + pow((p1.z - p2.z),2));
}

int comparar(const void* a, const void* b) {
    float d1 = ((vecino*)a)->distancia;
    float d2 = ((vecino*)b)->distancia;
    return (d1 > d2) - (d1 < d2); // devuelve 1, 0 o -1
}

char* knn(punto dataset[], int n, punto nuevoPunto, int k) {
    vecino vecinos[N];

    // Calcular distancias y guardar índices
    for (int i = 0; i < n; i++) {
        vecinos[i].distancia = distancia(nuevoPunto, dataset[i]);
        vecinos[i].indice = i;
    }

    // Ordenar vecinos por distancia
    qsort(vecinos, n, sizeof(vecino), comparar);

    // Contar clases
    int contadorA = 0, contadorB = 0;

    for (int i = 0; i < k; i++) {
        int idx = vecinos[i].indice;
        if (strcmp(dataset[idx].clase, "A") == 0)
            contadorA++;
        else if (strcmp(dataset[idx].clase, "B") == 0)
            contadorB++;
    }

    return (contadorA > contadorB) ? "A" : "B";
}
