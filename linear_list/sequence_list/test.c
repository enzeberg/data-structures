#include "sq_list.c"
#include <stdio.h>
#include <windows.h>

int compare(int a, int b);

void main() {
    SqList list;
    initList(&list, 10);
    // initialize
    // printf("list.ele=%d\n", list.ele);
    // printf("*(list.ele)=%d\n", *(list.ele));
    // printf("&(list.ele[0])=%d\n", &(list.ele[0]));
    // printf("\n");
    // printf("list.ele+1=%d\n", list.ele + 1);
    // printf("&(list.ele[1])=%d\n", &(list.ele[1]));
    // printf("\n");
    // printf("list.length=%d\n", list.length);
    // printf("list.size=%d\n", list.size);

    // insert
    // insert(&list, 5, 10);
    insert(&list, 1, 1);
    insert(&list, 2, 2);
    insert(&list, 3, 3);
    insert(&list, 4, 4);
    printList(list);
    // insert(&list, 2, 100);
    // printList(list);

    // deleteOne
    // int deleted;
    // deleteOne(&list, 3, &deleted);
    // printf("deleted: %d\n", deleted);
    // printList(list);

    // locateEle
    // int toLocate = 5;
    // int location = locateEle(list, toLocate, compare);
    // printf("location: %d\n", location);

    // mergeList
    SqList list1;
    initList(&list1, 10);
    insert(&list1, 1, 2);
    insert(&list1, 2, 3);
    insert(&list1, 3, 5);
    printList(list1);
    SqList list2;
    mergeList(list, list1, &list2);
    printList(list2);
    system("pause");
}

int compare(int a, int b) {
    return a == b;
}