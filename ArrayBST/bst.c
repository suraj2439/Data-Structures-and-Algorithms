#include <stdio.h>
#include "bst.h"


void init(bst *tree, int size) {
	tree->arr = (int*)malloc(sizeof(int) * size);
	tree->size = size;
	for(int i = 0; i<size; i++)
		(tree->arr)[i] = INT_MAX;
	return;
}


void insert(bst tree, int data) {
	int *arr = tree.arr;
	int size = tree.size;
	// tree is null
	if (arr[0] == INT_MAX) {
		arr[0] = data;
		return;
	}

	int indx = 0;
	while(indx < size) {
		if(arr[indx] == INT_MAX) {
			arr[indx] = data;
			return;
		}
		else if(data < arr[indx]) {
			indx = 2*indx + 1;
		}
		else
			indx = 2*indx + 2;
	}
	return;
}

int search(bst tree, int data) {
	int *arr = tree.arr;
	int size = tree.size;

	// tree is null
        if (arr[0] == INT_MAX)
                return 0;

        int indx = 0;
        while(indx < size) {
                if(data == arr[indx]) {
                        return 1;
                }
                else if(data < arr[indx]) {
                        indx = 2*indx + 1;
                }
                else
                        indx = 2*indx + 2;
        }
        return 0;

}


void trav_inord(int *arr, int indx) {
	if(arr[indx] == INT_MAX)
		return;

	// print left subtree 
	trav_inord(arr, 2*indx + 1);

	// print root 
	printf("%d  ", arr[indx]);

	// print right subtree 
	trav_inord(arr, 2*indx + 2);
}

void inorder_traverse(bst tree) {
	trav_inord(tree.arr, 0);
	printf("\n");
}



void trav_preord(int *arr, int indx) {
	if(arr[indx] == INT_MAX)
                return;

	// print root
        printf("%d  ", arr[indx]);

        // print left subtree 
        trav_preord(arr, 2*indx + 1);

        // print right subtree 
        trav_preord(arr, 2*indx + 2);
}

void preorder_traverse(bst tree) {
	trav_preord(tree.arr, 0);
	printf("\n");
}



void trav_postord(int *arr, int indx) {
        if(arr[indx] == INT_MAX)
                return;

        // print left subtree 
        trav_postord(arr, 2*indx + 1);

        // print right subtree 
        trav_postord(arr, 2*indx + 2);

	// print root
        printf("%d  ", arr[indx]);
}

void postorder_traverse(bst tree) {
	trav_postord(tree.arr, 0);
	printf("\n");
}


int isComplete(bst tree) {
    int i = 0, flag = 0;
    int size = tree.size;
    while(i < size) {
        //if data at index i is not INT_MAX and flag is set to 1 then tree is incomplete
        if(tree.arr[i] != INT_MAX && flag)
            return 0;
        //set flag to 1 when INT_MAX is encountered
        if(tree.arr[i] == INT_MAX)
            flag = 1;
        i++;
    }
    //if flag still remained 0 or tree incomplete condition is not encountered then tree is complete
    return 1;

}
