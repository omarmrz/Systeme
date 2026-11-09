//
// Created by Omar Can Mirzaoglu on 28/10/26.
//

#include "dll.h"
#include <stdlib.h>


bool DLLInit(DLLList* list) {
    if (list == NULL) {
        return false;
    }

    list->head = NULL;
    list->tail = NULL;
    list-> size = 0;
    return true;
}

bool DLLPushBack(DLLList* list, double value) {
    if (list == NULL) {
        return false;
    }

    DLLNode* node = (DLLNode*)malloc(sizeof(DLLNode));
    if (node == NULL) {
        return false;
    }

    node->value = value;
    node->next = NULL;
    node -> prev = list->tail;

    if (list->tail == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }

    list->tail = node;
    list->size++;
    return true;
}

void DLLClear(DLLList* list) {
    if (list == NULL) {
        return;
    }

    DLLNode* p = list->head;
    while (p != NULL) {
        DLLNode* next = p->next;
        free(p);
        p = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}