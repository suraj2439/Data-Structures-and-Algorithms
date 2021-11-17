#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "expr_tree.h"

typedef struct opr_node{
	char num;
        struct opr_node* next;
} opr_node;

typedef opr_node* opr_stack;


typedef struct val_node {
        tree_node subexpr;
        struct val_node *next;
} val_node;

typedef val_node *val_stack;


void init_opr_stack(opr_stack *s);

void push_opr(opr_stack *head, char num);

char pop_opr(opr_stack *head);

char peek_opr(opr_stack st);

int isEmpty_opr(opr_stack st);


void init_val_stack(val_stack *s);

void push_val(val_stack *head, val_node *nn);

val_node* pop_val(val_stack *head);

#endif
