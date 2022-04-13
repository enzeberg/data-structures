#include "windows.h"
#include "singly_linked_list.c"
// #include "print_list.c"

void main() {
    // LNode *list;
    SinglyLinkedList list;
    // createList_TIM(&list, 30);
    createList_HIM(&list, 6);
    printList(list);

    // getEle
    // int a;
    // getEle(list, 3, &a);
    // printf("get: %d\n", a);

    // deleteEle
    // int a;
    // deleteEle(&list, 12, &a);
    // printf("deleted: %d\n", a);
    // printList(list);

    // insertEle
    // printf("insertEle(&list, 4, 4);\n");
    // insertEle(&list, 4, 4);
    // printList(list);
    // printf("insertEle(&list, 2, 10);\n");
    // insertEle(&list, 2, 10);
    // printList(list);
    insertEle(&list, 1, 100);
    printList(list);
    // insertEle(&list, 100, 1);
    // insertEle(&list, 0, 1);
    // printList(list);

    // merge
    // SinglyLinkedList list1;
    // createList_TIM(&list1, 3);
    // printf("list1: \n");
    // printList(list1);

    // SinglyLinkedList list2;
    // merge(list, &list1, &list2);
    // printf("after merge: \n");
    // printList(list2);
    // printf("\nLa:\n");
    // printList(list);
    system("pause");
}