#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "bst.h"


int main() {
	bst bst;
	init(&bst, 100);

	insert(bst, 25);
	insert(bst, 15);
	insert(bst, 50);
        insert(bst, 10);
	insert(bst, 22);
        insert(bst, 35);
	insert(bst, 70);
        insert(bst, 4);
        insert(bst, 12);
        insert(bst, 18);
        insert(bst, 24);
        insert(bst, 31);
	insert(bst, 44);
        insert(bst, 66);
        insert(bst, 90);
	
	postorder_traverse(bst);
	if(isComplete(bst)) 
		printf("tree is complete tree\n");
	else
		printf("tree is not complete tree\n");
	return 0;	

}

