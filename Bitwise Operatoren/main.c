//
// Created by Omar Can Mirzaoglu on 21/10/26.
//
#include <stdint.h>


#include <stdio.h>


void bits(uint16_t zahl) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (zahl >> i) & 1);
        if (i == 8) {
            printf(" ");
        }
    }
}

int main() {
    uint16_t A = 0;
    uint16_t B = 0;
    int wahl;

    do {
        printf("\nA Hex: %04X Bits: ", A);
        bits(A);
        printf("\nB Hex: %04X Bits: ", B);
        bits(B);

        printf("\n\n1 A eingeben");
        printf("\n2 B eingeben");
        printf("\n3 A = A + B");
        printf("\n4 A = A UND B");
        printf("\n5 A = A ODER B");
        printf("\n6 A = A XOR B");
        printf("\n7 A = NICHT A");
        printf("\n8 links schieben");
        printf("\n9 rechts schieben");
        printf("\n10 bit setzen");
        printf("\n11 bit loeschen");
        printf("\n12 bit umschalten");
        printf("\n13 bit pruefen");
        printf("\n0 ende");
        printf("\nwahl: ");

        if (scanf("%d", &wahl) != 1) {
            while (getchar() != '\n');
            wahl = -1;
        }

        if (wahl == 1) {
            printf("A eingeben (Hex): ");
            scanf("%hx", &A);
        } else if (wahl == 2) {
            printf("B eingeben (Hex): ");
            scanf("%hx", &B);
        }
        else if (wahl == 3) {
            A = A + B;
            printf("A Hex: %04X Bits: ", A);
            bits(A);
            printf("\n");
        }
        else if (wahl == 4) {
            A = A & B;
            printf("A Hex: %04X Bits: ", A);
            bits(A);
            printf("\n");
        }
        else if (wahl == 5) {
            A = A | B;
            printf("A Hex: %04X Bits: ", A);
            bits(A);
            printf("\n");
        }
        else if (wahl == 6) {
            A = A ^ B;
            printf("A Hex: %04X Bits: ", A);
            bits(A);
            printf("\n");
        }
        else if (wahl == 7) {
            A = ~A;
            printf("A Hex: %04X Bits: ", A);
            bits(A);
            printf("\n");
        }


    } while (wahl != 0);

    return 0;






    }



