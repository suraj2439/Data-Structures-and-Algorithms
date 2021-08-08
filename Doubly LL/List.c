#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next, *prev;
} node;

typedef node* DLL;

void initDLL(DLL *l) {
    *l = NULL;
    return;
}

void insertEnd(DLL *l, int data) {
    node* p = *l;
    node* nn = (node*)malloc(sizeof(node));
    nn->data = data;
    nn->next = nn->prev = NULL;
    if(!p) *l = nn;

    while(p->next) p = p->next;

    p->next = nn;
    nn->prev = p;
    return;
}

void insertBegin(DLL *l, int data) {
    node *p = *l;
    node* nn = (node*)malloc(sizeof(node));
    nn->data = data;
    nn->next = nn->prev = NULL;
    if(!p) {
        *l = nn;
        return;
    }
    *l=nn;
    nn->next = p;
    p->prev = nn;
    return;
}

void deleteNode(DLL *l, int data) {
    node *p = *l;
    if(!p)  return;
    if(p->data == data) {
        *l = p->next;
        if(p->next)
            p->next->prev = NULL;
        free(p);
        return;
    }

    while(p->next) {
        if(p->next->data == data) {
            node *tmp = p->next;
            p->next = tmp->next;
            if(tmp->next)
                tmp->next->prev = p;
            free(tmp);
            return;
        }
        p = p->next;
    } 
}

void printDLL(DLL l) {
    DLL tmp = l;
    while(l) {
        printf("%d ", l->data);
        tmp = l;
        l = l->next;
    }
    printf("\n");
    while(tmp) {
        printf("%d ", tmp->data);
        tmp = tmp->prev;
    }
}

int main() {   
    printf("insertbegin, insertend, delete, print\n");
    int choice;
    DLL l;
    initDLL(&l);
    while(1) {
        scanf("%d", &choice);
        if(choice == 1) {
            int data;
            scanf("%d", &data);
            insertBegin(&l, data);
        }
        else if(choice == 2) {
            int data;
            scanf("%d", &data);
            insertEnd(&l, data);
        }
        else if(choice == 3) {
            int data;
            scanf("%d", &data);
            deleteNode(&l, data);
        }
        else printDLL(l);
        printf("\n-----------------\n");
    }

    return 0;
}
