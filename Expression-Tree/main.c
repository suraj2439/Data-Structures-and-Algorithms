#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "expr_tree.h"
#include "stack.h"

#define MAX	100

int main() {
	tree expr;

        char inp[MAX];
        scanf("%[^\n]s", inp);

	Init_Tree(&expr, inp);
	printf("Inorder Traversal of Expression tree is : ");
	Inorder(expr);
	printf("\n");

	compute(expr);
	return 0;
}


