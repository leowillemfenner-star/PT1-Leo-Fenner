#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Wichtig: dieses print-statement darf nicht verändert werden!
    printf("Bitte geben Sie die Größe des Diamantenmusters ein:\n");
    int n;
if (scanf("%d", &n) != 1) {
    fprintf(stderr,"Fehler: Ungültige Eingabe. Bitte eine Ganzzahl eingeben. \n");
    return 1;
}
if (n <= 2 || n % 2 == 0) {
    fprintf(stderr, "Fehler: Die Größe , muss eine Ungerade Zahl größer als 2 sein.\n");
    return 1;
}
int mid = n/2; 
for (int i = 0; i < n; i++) {
    int starts = (i <= mid) ? 2 * i + 1 : 2 * (n - i - 1) + 1;
    int spaces = (n - starts) / 2;
    for (int j = 0; j < spaces; j++) {
        printf(".");
    }
    for (int j = 0; j < starts; j++) {
        printf("*");
    }
    for (int j = 0; j < spaces; j++) {
        printf(".");   
    }
    printf("\n");
    // TODO
}
    return 0;
}
