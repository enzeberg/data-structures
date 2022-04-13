#include "singly_linked_list.h"

// 尾插法
void createList_TIM(SinglyLinkedList *l, int n) {
    // *l 为指针变量，头指针，指向头结点 *(*l)
    *l = (SinglyLinkedList)malloc(sizeof(LNode));
    (*l)->next = NULL;
    LNode *r = *l; // 表尾指针
    LNode *node;
    for (int i = 1; i <= n; ++i) {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = i;
        r->next = node;
        r = node;
    }
    r->next = NULL;
}

// 头插法
void createList_HIM(SinglyLinkedList *l, int n) {
    LNode *node;
    *l = (SinglyLinkedList)malloc(sizeof(LNode));
    (*l)->next = NULL;
    for (int i = n; i > 0; --i) {
        node = (LNode *)malloc(sizeof(LNode));
        node->data = i;
        node->next = (*l)->next;
        (*l)->next = node;
    }
}

void getEle(SinglyLinkedList l, int i, int *ele) {
    LNode *p = l->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return;
    *ele = p->data;
}

void deleteEle(SinglyLinkedList *l, int i, int *deleted) {
    LNode *p = *l, *t;
    int j = 1;
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i) return;
    t = p->next;
    *deleted = t->data;
    p->next = t->next;
    free(t);
}

void insertEle(SinglyLinkedList *l, int i, int ele) {
    LNode *p = *l;
    int j = 1;
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }
    if (j != i) return; // wrong insertion position
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = ele;
    if (p->next) {
        node->next = p->next;
    } else {
        node->next = NULL;
    }
    p->next = node;
}

void merge(SinglyLinkedList La, SinglyLinkedList *Lb, SinglyLinkedList *Lc) {
    LNode *pa = La->next, *pb = (*Lb)->next;
    *Lc = La;
    LNode *pc = *Lc;
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa) pc->next = pa;
    if (pb) pc->next = pb;
    free(*Lb);
}

void printList(SinglyLinkedList l) {
    LNode *p = l;
    while (p->next) {
        p = p->next;
        printf("%d\n", p->data);
    }
}