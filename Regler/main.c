//
// Created by Omar Can Mirzaoglu on 27/10/26.
//
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    double solltemperatur = 22.0;
    double temperatur = 20.0;

    double hysterese = 1.0;

    bool heizung = false;

    FILE *datei = fopen("simulation.csv", "w");

    fprintf(datei, "Schritt,Temperatur,Solltemperatur,Heizung\n");


    for (int i = 0; i < 1000; i++) {

        if (temperatur < solltemperatur - hysterese / 2) {
            heizung = true;
        }
        else if (temperatur > solltemperatur + hysterese / 2) {
            heizung = false;
        }

        fprintf(datei, "%d,%.2f,%.2f,%s\n",
               i, temperatur, solltemperatur,
               heizung ? "EIN" : "AUS");

        if (heizung) {
            temperatur += 0.5;
        }
        else {
            temperatur -= 0.1;
        }

        printf("Schritt: %d | Temperatur: %.2f °C | Heizung: %s\n",
              i, temperatur, heizung ? "EIN" : "AUS");
    }

    fclose(datei);

    return 0;

}