#include "sq_list.h"

#include <stdio.h>
#include <stdlib.h>

void initList(SqList *l, int listSize) {
    (*l).ele = (int *)malloc(listSize * sizeof(int));
    if (!l->ele)
        exit(-1);
    (*l).length = 0;
    (*l).size = listSize;
}

// 1 <= i <= l->length + 1
void insert(SqList *l, int i, int ele) {
    if (i < 1 || i > l->length + 1)
        exit(printf("Incorrect insertion position."));
    int *q = l->ele + i - 1; // insertion position
    if (l->length >= l->size) {
        int *newBase = (int *)realloc(l->ele,
          (l->size + INCREMENT) * sizeof(int));
        if (!newBase) exit(-1);
        l->size += INCREMENT;
    }
    for (int *p = l->ele + l->length - 1; p >= q; --p) {
        *(p + 1) = *p;
    }
    *q = ele;
    ++(l->length);
}

void deleteOne(SqList *l, int i, int *ele) {
    if (i < 1 || i > l->length)
        exit(printf("Incorrect deletion position."));
    int *p = l->ele + l->length - 1;
    int *q = l->ele + i - 1;
    *ele = *q;
    for (; q < p; ++q) {
        *q = *(q + 1);
    }
    --(l->length);
}

int locateEle(SqList l, int ele, int (compare)(int a, int b)) {
    int i = 1;
    while (i <= l.length && !compare(*(l.ele + i - 1), ele))
        ++i;
     
    return i <= l.length ? i : 0;
}

void mergeList(SqList l1, SqList l2, SqList *l3) {
    initList(l3, l1.length + l2.length);
    int *p = l1.ele;
    int *q = l2.ele;
    int i = 1;
    while (p < l1.ele + l1.length && q < l2.ele + l2.length) {
        insert(l3, i++, *p <= *q ? *(p++) : *(q++));
    }
    while (p < l1.ele + l1.length)
        insert(l3, i++, *(p++));
    while (q < l2.ele + l2.length)
        insert(l3, i++, *(q++));
}

void printList(SqList l) {
    printf("\nlist content:\n");
    for(int i = 0; i < l.length; ++i) {
        printf("%d\n", *(l.ele + i));
    }
}