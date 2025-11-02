#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

int main(void) {

    srand(time(NULL));
    for (int i = 0; i < 10; i++){
        int zahl = rand()%100+1;
        printf("d\n", zahl);
    }
    return 0; 
    }
    
// Das Problem ist, dass die Funktion rand() bei jedem Programmstart die gleiche Zahelenfolge ausgibt, wenn man kein "Seed" setzt. Dadurch is der Zufall nicht wirklich zufällig.
// Die Lösung ist, dass man den Zufallsgenertor mit srand(time(NULL)) initialisiert, wodurch der Startwert ( der "Seed") mit der Aktuellen Uhrueit gesetzt wird und jedes Programm drucht immer eine andere Zufallsfolge erzeugt. 