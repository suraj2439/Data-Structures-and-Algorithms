#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct queue {
    int *arr;
    int front, rear;
    int max_size, size;
} queue;

void init(queue *q, int size) {
    (*q).arr = (int*)malloc(sizeof(int)*size);
    (*q).front = (*q).rear = -1;
    (*q).size = 0;
    (*q).max_size = size;
}

void push(queue *q, int data) {
    if((*q).size == (*q).max_size) 
        return;
    if((*q).size == 0) {
        (*q).front = (*q).rear = 0;
        (*q).arr[(*q).rear] = data;
        (*q).size++;
        return;
    }

    (*q).arr[(*q).rear] = data;
    (*q).rear = ((*q).rear + 1) % (*q).size;
    (*q).size++;
}

int pop(queue *q) {
    if((*q).size == 0) return INT_MAX;

    int val = (*q).arr[(*q).front--];
    if((*q).front < 0)
        (*q).front = (*q).max_size-1;
    (*q).size--;
    return val;
}

int peek(queue q) {
    if(q.size == 0)
        return INT_MAX;
    return q.arr[q.front];
}

int main(int argc, char const *argv[]) {
    printf("push, pop, peek\n");
    int choice;
    queue l;
    init(&l, 3);
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
