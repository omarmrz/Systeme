//
// Created by Omar Can Mirzaoglu on 28/10/26.
//

#include <stdio.h>
#include "dll.h"


int main (void) {
    DLLList list;
    DLLInit(&list);

    if (!DLLPushBack(&list, 10.5) ||
        !DLLPushFront(&list, 20.5) ||
        !DLLPushBack(&list, 30.5)) {
        DLLClear(&list);
        return 1;
    }

    printf("Vorwaerts: [ ");
    for (DLLNode* p = list.head; p != NULL; p = p->next) {
        printf("%.2f ", p->value);
    }
    printf("]\n");

    printf("Rueckwaerts: [ ");
    for (DLLNode* p = list.tail; p != NULL; p = p->prev) {
        printf("%.2f ", p->value);
    }
    printf("]\n");

    double value;

    if (DLLPopFront(&list, &value)) {
        printf("Pop Front: %.2f\n", value);
    }

    if (DLLPopBack(&list, &value)) {
        printf("Pop Back: %.2f\n", value);
    }

    if (DLLPopFront(&list, &value)) {
        printf("Pop Front: %.2f\n", value);
    }

    if (!DLLPopBack(&list, &value)) {
        printf("Liste ist leer.\n");
    }

    if (!DLLPushBack(&list, 10.5) ||
    !DLLPushBack(&list, 20.5) ||
    !DLLPushBack(&list, 30.5)) {
        DLLClear(&list);
        return 1;
    }

    printf("Suche 20.50: Position %lld\n",
           (long long)DLLSearch(&list, 20.5));
    printf("Suche 99.00: Position %lld\n",
           (long long)DLLSearch(&list, 99.0));

    if (DLLRemoveAt(&list, 1)) {
        printf("Position 1 entfernt.\n");
    }

    printf("Vorwaerts: [ ");
    for (DLLNode* p = list.head; p != NULL; p = p->next) {
        printf("%.2f ", p->value);
    }
    printf("]\n");

    printf("Rueckwaerts: [ ");
    for (DLLNode* p = list.tail; p != NULL; p = p->prev) {
        printf("%.2f ", p->value);
    }
    printf("]\n");

    DLLClear(&list);
    return 0;
}