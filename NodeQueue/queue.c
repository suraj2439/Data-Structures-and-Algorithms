#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void init(queue *q) {
    (*q).front = (*q).rear = NULL;
}

void push(queue *q, int data) {
    node *nn = (node*)malloc(sizeof(node));
    nn->data = data;
    nn->next = NULL;

    if((*q).rear == NULL) {
        (*q).front = (*q).rear = nn;
        return;
    }
    (*q).rear->next = nn;
    (*q).rear = nn;
    return;
}

int pop(queue *q) {
    if((*q).front == NULL) return INT_MAX;

    if((*q).front == (*q).rear) {
        int val = (*q).front->data;
        (*q).front = (*q).rear = NULL;
        return val;
    }

    int val = (*q).front->data;
    (*q).front = (*q).front->next;
    return val;
}

int peek(queue q) {
    if(q.front == NULL)
        return INT_MAX;
    return q.front->data;
}

int main(int argc, char const *argv[]) {
    printf("push, pop, peek\n");
    int choice;
    queue l;
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

