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

    

    DLLClear(&list);
    return 0;
}