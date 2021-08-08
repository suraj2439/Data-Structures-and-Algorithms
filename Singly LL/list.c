#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initLL(list *l) {
    *l = NULL;
    return;
}

void insertEnd(list *l, int data) {
    node *p = *l;
    node *nn = (node *)malloc(sizeof(node));
    nn->data = data;
    nn->next = NULL;
    if(p == NULL) {
        *l = nn;
        return;
    }

    while(p->next) 
        p = p->next;
    p->next = nn;
    return;
}

void insertBegin(list *l, int data) {
    node *p = *l;
    node *nn = (node *)malloc(sizeof(node));
    nn->data = data;
    nn->next = NULL;
    *l = nn;
    nn->next = p;
    return;
}

void deleteNode(list *l, int data) {
    node *p = *l;
    if(p == NULL)
        return;
    if(p->data == data) {
        node *tmp = p;
        *l = p->next;
        free(tmp);
    }
    
    while(p && p->next) {
        if(p->next->data == data) {
            node *tmp = p->next;
            p->next = p->next->next;
            free(tmp);
            return;
        }
        p = p->next;
    }
}

void printLL(list l) {
    while(l) { 
        printf("%d ", l->data);
        l = l->next;
    }
}


int main() {   
    printf(" insertbegin, insertend, delete, print\n");
    int choice;
    list l;
    initLL(&l);
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
        else printLL(l);
        printf("\n-----------------\n");
    }

    return 0;
}


