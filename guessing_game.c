#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int geheimzahl = rand()% 101; 
    int tipp;
    int versuche = 0;
    printf("Ich habe mir eine Zahl zwischen 0 und 100 ausgedacht, kannst du sie erraten?.\n");

    do {
    printf("Rat mal: ");
    scanf("%d", &tipp);
    versuche++;
    if (tipp < geheimzahl) {
        printf("Zu niedrig! Versuch es nochmal.\n");
    } else if (tipp > geheimzahl) {
        printf("Zu hoch! Versuch es nochmal.\n");
    } else {
        printf("Glückwunsch! Du hast die Zahl %d in %d Versuchen erraten.\n", geheimzahl, versuche);
    }
    } while (tipp != geheimzahl);    
     printf("Du hast %d Versuche gebraucht.\n", versuche);
     return 0;

    }

    