#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack {
    int *arr;
    int indx;
    int size;
} stack;

void init(stack *st, int size) {
    (*st).arr = (int*)malloc(sizeof(int)*size);
    (*st).indx = 0;
    (*st).size = size;
}

void push(stack *st, int data) {
    if((*st).indx >= (*st).size)
        return;
    (*st).arr[(*st).indx++] = data;
}

int pop(stack *st) {
    if((*st).indx == 0)
        return INT_MAX;
    return (*st).arr[--(*st).indx];
}

int peek(stack st) {
    if(st.indx == 0)
        return INT_MAX;
    return st.arr[st.indx-1];
}

int main(int argc, char const *argv[]) {
    printf("push, pop, peek\n");
    int choice;
    stack l;
    init(&l, 10);
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