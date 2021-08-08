#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef node* stack;

void init(stack *st) {
    *st = NULL;
    return;
}

void push(stack *head, int data) {
    stack st = *head;
    node *nn = (node*)malloc(sizeof(node));
    nn->data = data;
    nn->next = NULL;
    
    if(!st) {
        *head = nn;
        return;
    }
    nn->next = st;
    *head = nn;
    return;
}

int pop(stack *head) {
    stack st = *head;
    if(!st)
        return INT_MAX;
    int val = st->data;
    *head = st->next;
    return val;
}

int peek(stack head) {
    if(!head)
        return INT_MAX;
    return head->data;
}


int main(int argc, char const *argv[]) {
    printf("push, pop, peek\n");
    int choice;
    stack l;
    init(&l);
    while(1) {
        scanf("%d", &choice);
        if(choice == 1) {
            int data;
            scanf("%d", &data);
            push(&l, data);
        }
        else if(choice == 2) {
            printf("%d\n", pop(&l));
        }
        else if(choice == 3) {
            printf("%d\n", peek(l));
        }
        printf("\n-----------------\n");
    }

    return 0;
}

