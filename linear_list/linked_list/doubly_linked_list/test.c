#include "doubly_linked_list.c"
#include <windows.h>

void main() {
    DoublyLinkedList L;
    initList(&L);

    insertEle(&L, 1, 3);
    insertEle(&L, 1, 2);
    insertEle(&L, 1, 1);
    insertEle(&L, 4, 23);
    insertEle(&L, 5, 34);
    printListByNext(L);
    printListByPrior(L);
    insertEle(&L, 60, 10);
    printf("\n");

    printf("deleteEle:\n");
    int deleted;
    deleteEle(&L, 3, &deleted);
    printf("deleted: %d\n", deleted);
    printListByNext(L);
    printListByPrior(L);

    deleteEle(&L, 1, &deleted);
    printf("deleted: %d\n", deleted);
    printListByNext(L);
    printListByPrior(L);

    deleteEle(&L, 3, &deleted);
    printf("deleted: %d\n", deleted);
    printListByNext(L);
    printListByPrior(L);
    
    deleteEle(&L, 10, &deleted);

    system("pause");
}