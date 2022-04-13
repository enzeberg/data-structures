#define MAXSIZE 50

typedef struct SeqList *ListPointer;

struct SeqList {
    int data[MAXSIZE];
    int last;
};

// struct SeqList l;
// ListPointer p;

ListPointer initList() {
    ListPointer p;
    // p = (ListPointer)malloc(sizeof(struct SeqList));
    p->last = -1;
    
    return p;
}