#include "doubly_linked_list.h"

void initList(DoublyLinkedList *l) {
    *l = (DoublyLinkedList)malloc(sizeof(DNode));
    (*l)->prior = (*l)->next = *l;
}

int listLength(DoublyLinkedList l) {
    DNode *p = l->next;
    int i = 0;
    while (p != l) {
        ++i;
        p = p->next;
    }
    return i;
}

DNode* getElePtr(DoublyLinkedList l, int i) {
    DNode *p = l->next;
    int j = 1;
    while (p != l && j < i) {
        p = p->next;
        ++j;
    }
    return p != l ? p : NULL;
}

void insertEle(DoublyLinkedList *l, int i, int ele) {
    if (i < 1 || i > listLength(*l) + 1) {
        printf("Num: %d, cannot insert at %d¸\n", listLength(*l), i);
        return;
    }
    DNode *p = getElePtr(*l, i);
    if (p == NULL) p = *l;

    DNode *node = (DNode *)malloc(sizeof(DNode));
    node->data = ele;
    node->next = p;
    node->prior = p->prior;
    p->prior->next = node;
    p->prior = node;
}

void deleteEle(DoublyLinkedList *l, int i, int *ele) {
    if (i < 1 || i > listLength(*l)) {
        printf("Num: %d, cannot delete %d¸\n", listLength(*l), i);
        return;
    }
    DNode *p = getElePtr(*l, i);
    *ele = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
}

void printListByNext(DoublyLinkedList l) {
    DNode *p = l->next;
    int i = 1;
    printf("printListByNext:\n");
    while (p != l) {
        printf("%d: %d\n", i, p->data);
        p = p->next;
        ++i;
    }
    printf("\n");
}

void printListByPrior(DoublyLinkedList l) {
    DNode *p = l->prior;
    int i = 1;
    printf("printListByPrior:\n");
    while (p != l) {
        printf("%d count backwards: %d\n", i, p->data);
        p = p->prior;
        ++i;
    }
    printf("\n");
}