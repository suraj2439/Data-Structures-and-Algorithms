#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct bst {
	int *arr;
	int size;
} bst;


void init(bst *tree, int size);

void insert(bst tree, int data);

int search(bst tree, int data);

void inorder_traverse(bst tree);

void preorder_traverse(bst tree);

void postorder_traverse(bst tree);

int isComplete(bst tree);

#endif
