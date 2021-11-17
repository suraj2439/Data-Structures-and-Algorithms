#ifndef EXPR_TREE_H
#define EXPR_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#define MAX	100

typedef struct tree_node {
	int data;
	struct tree_node *left, *right;
} tree_node;

#include "stack.h"

typedef tree_node *tree;


int precedence(char c);

int isOperator(char c);

void Inorder(tree t);;

void Init_Tree(tree *root, char *inp);

int eval(tree root);

void compute(tree root);

#endif
