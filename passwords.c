#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool passwordIsPrintable(char password[])
{
    // Alle druckbaren ASCII-Zeichen liegen zwischen 32 und 126
    for (int i = 0; i < strlen(password); i++)
    {
        if (password[i] < 32 || password[i] > 126)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char password[43]; // Maximal 42 Zeichen + Nullterminator
    printf("Bitte geben Sie ein Passwort ein:\n");
    if (scanf("%42s", password) != 1)
    {
        fprintf(stderr, "Fehler beim Einlesen des Passworts.\n");
        return 1;
    }

    // Prüfen, ob alle Zeichen druckbar sind
    if (!passwordIsPrintable(password))
    {
        fprintf(stderr, "Fehler: Passwort enthält undruckbare Zeichen.\n");
        return 1;
    }

    int length = strlen(password);

    // Ermitteln, welche Zeichengruppen vorkommen
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (int i = 0; i < length; i++)
    {
        if (password[i] >= 'a' && password[i] <= 'z') hasLower = true;
        else if (password[i] >= 'A' && password[i] <= 'Z') hasUpper = true;
        else if (password[i] >= '0' && password[i] <= '9') hasDigit = true;
        else hasSpecial = true;
    }

    // Summe der Zeichenanzahlen der genutzten Gruppen
    int charset = 0;
    if (hasLower) charset += 26;
    if (hasUpper) charset += 26;
    if (hasDigit) charset += 10;
    if (hasSpecial) charset += 33;

    // Entropie berechnen
    double entropy = length * log2(charset);

    // Stärke einschätzen
    char *strength;
    if (entropy < 40) strength = "schwach";
    else if (entropy >= 80) strength = "stark";
    else strength = "mittel";

    // Ergebnis ausgeben
    printf("Entropie: %.1f\n", entropy);
    printf("Stärke: %s\n", strength);

    return 0;
}
