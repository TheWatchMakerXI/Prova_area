#include <stdio.h>
#include <math.h>
int main() {
    int D;
    const float pi=3.14;
    // Richiede l'inserimento del valore da tastiera
    printf("Inserisci il valore di D: ");
    scanf("%d", &D);

    // Calcola l'area del quadrato
    int areaQ = D * D;
    float areacerchio = (D/2)*(D/2)*pi;
    float areatriangolo = 
    // Stampa il risultato
    printf("L'area del quadrato di lato %d e': %d\n", D, areaQ);
    printf("L'area del cerchio di diametro %d e': %lf\n", D, areacerchio);
    return 0;
}