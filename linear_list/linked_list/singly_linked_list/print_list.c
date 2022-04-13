// #include <stdio.h>
#include "singly_linked_list.c"

// needs to be placed in singly_linked_list.c
void printList(SinglyLinkedList l) {
    LNode *p = l;
    while (p->next) {
        p = p->next;
        printf("%d\n", p->data);
    }
}