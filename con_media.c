#include <stdio.h>

// Definizione di PI approssimato
#define PI 3.14

// Funzione per calcolare la radice quadrata approssimata usando il metodo di Newton
double sqrt_approx(double number) {
    double x = number;
    double y = 1.0;
    double epsilon = 0.000001; // Precisione desiderata
    while (x - y > epsilon) {
        x = (x + y) / 2;
        y = number / x;
    }
    return x;
}

int main() {
    int n, i;
    double sum = 0.0, mean, rounded_mean;
    double area_square_dec, area_square_int;
    double area_circle_dec, area_circle_int;
    double area_triangle_dec, area_triangle_int;
    
    printf("Quanti numeri vuoi inserire (minimo 3)? ");
    scanf("%d", &n);
    
    if (n < 3) {
        printf("Devi inserire almeno 3 numeri.\n");
        return 1;
    }
    
    double numbers[n];
    
    printf("Inserisci i numeri:\n");
    for (i = 0; i < n; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%lf", &numbers[i]);
        sum += numbers[i];
    }
    
    mean = sum / n;
    rounded_mean = (mean > 0) ? (int)(mean + 0.5) : (int)(mean - 0.5); // Arrotondamento manuale
    
    // Calcolare le aree con il valore decimale
    area_square_dec = mean * mean;
    area_circle_dec = PI * mean * mean;
    area_triangle_dec = (sqrt_approx(3) / 4) * mean * mean;
    
    // Calcolare le aree con il valore arrotondato
    area_square_int = rounded_mean * rounded_mean;
    area_circle_int = PI * rounded_mean * rounded_mean;
    area_triangle_int = (sqrt_approx(3) / 4) * rounded_mean * rounded_mean;
    
    // Stampare i risultati
    printf("\nMedia aritmetica: %.2f\n", mean);
    printf("Media aritmetica arrotondata: %.0f\n", rounded_mean);
    
    printf("\nAree usando la media decimale:\n");
    printf("Area del quadrato: %.2f\n", area_square_dec);
    printf("Area del cerchio: %.2f\n", area_circle_dec);
    printf("Area del triangolo equilatero: %.2f\n", area_triangle_dec);
    
    printf("\nAree usando la media arrotondata:\n");
    printf("Area del quadrato: %.0f\n", area_square_int);
    printf("Area del cerchio: %.0f\n", area_circle_int);
    printf("Area del triangolo equilatero: %.0f\n", area_triangle_int);
    
    return 0;
}