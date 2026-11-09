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

bool DLLPushFront(DLLList* list, double value) {
    if (list == NULL) {
        return false;
    }

    DLLNode* node = malloc(sizeof(DLLNode));
    if (node == NULL) {
        return false;
    }

    node->value = value;
    node->next = list->head;
    node->prev = NULL;

    if (list->head == NULL) {
        list->tail = node;
    } else {
        list->head->prev = node;
    }

    list->head = node;
    list->size++;
    return true;
}

bool DLLPopFront(DLLList* list, double* value) {
    if (list == NULL || value == NULL || list->head == NULL) {
        return false;
    }

    DLLNode* node = list->head;
    *value = node->value;
    list->head = node->next;

    if (list->head == NULL) {
        list->tail = NULL;
    } else {
        list->head->prev = NULL;
    }

    free(node);
    list->size--;
    return true;
}

bool DLLPopBack(DLLList* list, double* value) {
    if (list == NULL || value == NULL || list->tail == NULL) {
        return false;
    }

    DLLNode* node = list->tail;
    *value = node->value;
    list->tail = node->prev;

    if (list->tail == NULL) {
        list->head = NULL;
    } else {
        list->tail->next = NULL;
    }

    free(node);
    list->size--;
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