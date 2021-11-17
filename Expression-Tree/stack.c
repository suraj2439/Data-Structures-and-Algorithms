#include "stack.h"

void init_opr_stack(opr_stack *s) {
        (*s) = NULL;
}

void push_opr(opr_stack *head, char num) {
        opr_stack nn;
        nn = (opr_node*)malloc(sizeof(opr_node));
        if(nn) {
                nn->num = num;
                nn->next = NULL;
        }
        else return;

        if(*head == NULL) {
                *head = nn;
                return;
        }
        nn->next = *head;
        *head = nn;
        return;
}

char pop_opr(opr_stack *head) {
        char empty, num;
        opr_stack temp;
        /*To indicate stack is empty*/
        empty = -128;
        if (*head == NULL)
                return empty;
        temp = *head;
        num = (*head)->num;
        *head = (*head)->next;
        free(temp);
        return num;
}

char peek_opr(opr_stack st) {
        if(st)
                return st->num;
        else return -128;
}

int isEmpty_opr(opr_stack st) {
        if(peek_opr(st) == -128){
                return 1;}
        else return 0;
}



void init_val_stack(val_stack *s) {
        (*s) = NULL;
}

void push_val(val_stack *head, val_node *nn) {
        if(*head == NULL) {
                *head = nn;
                return;
        }
        nn->next = *head;
        *head = nn;
        return;
}

val_node* pop_val(val_stack *head) {
        val_stack temp, empty;
	if(*head == NULL) {
		(temp->subexpr).data = INT_MAX;
		(temp->subexpr).left = (temp->subexpr).right = NULL;
		temp->next = NULL;
		return temp;
	}
        temp = *head;
        *head = (*head)->next;
	//temp->next = NULL;
        return temp;
}

/*
val_node* peek_val(opr_stack st) {
        if(st)
                return st->num;
        else return -128;
}*/

/*
int isEmpty_val(val_stack st) {
        if(peek_opr(st) == -128){
                return 1;}
        else return 0;
}
*/


