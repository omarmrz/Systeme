//
// Created by Omar Can Mirzaoglu on 28/10/26.
//

#ifndef SYSTEME_DLL_H
#define SYSTEME_DLL_H

#include <stdint.h>
#include <stdbool.h>


typedef struct DLLNode {
    double value;
    struct DLLNode* next;
    struct DLLNode* prev;
} DLLNode;

typedef struct {
    DLLNode* head;
    DLLNode* tail;
    uint64_t size;

} DLLList;

bool DLLInit(DLLList* list);

bool DLLPushBack(DLLList* list, double value);
bool DLLPushFront(DLLList* list, double value);





#endif //SYSTEME_DLL_H
