#include "expr_tree.h"

#define MAX	100

int precedence(char c) {
    switch(c) {
        case '(':
                return 5;
        case '+':
                return 10;
        case '-':
                return 10;
        case '*':
                return 20;
        case '/':
                return 20;
        default:
                return 0;

    }
}

int isOperator(char c) {
        switch(c) {
                case '+':
                        return 1;
                case '-':
                        return 1;
                case '*':
                        return 1;
                case '/':
                        return 1;
                default:
                        return 0;
        }
}

void Inorder(tree t){
    if (t == NULL)
        return;

    Inorder(t->left);

    if(t->left == NULL && t->right == NULL)
	    printf("%d ", t->data);
    else
	    printf("%c ", t->data);

    Inorder(t->right);
}


void error(char prev, char next) {
        printf("Syntax Error\n");
        printf("TYPE: wrong operator '%c', after '%c'.\n", next, prev);
        exit(1);
}


void handle_errors(char *inp, int indx) {
	char curr = inp[indx -1], prev = inp[indx -2], next = inp[indx];
	switch(curr) {
		case '/':
                        if(isOperator(prev))
                                error(prev, curr);
                        break;
                case '*':
                        if(isOperator(prev))
                                error(prev, curr);
                        break;
		case '+':
                        if(isOperator(prev))
                                error(prev, curr);
                        break;
		case '-':
                        if(isOperator(prev))
                                error(prev, curr);
                        break;
		case '\0':
                        if(isOperator(prev)) {
                                printf("Syntax Error.\n");
                                printf("TYPE: Unterminated operator '%c'\n", prev);
				exit(1);
                        }
                        break;
	}

}

void Init_Tree(tree *root, char *inp) {
	int num = 0, indx = 0;
	char token;
	char operan;
	val_node *nn, *op1, *op2;

	opr_stack opr;
	val_stack val;
	init_opr_stack(&opr);
	init_val_stack(&val);

	token = inp[indx++];
	while(token != '\0') {
		/*If token is digit.*/
		if(isdigit(token)) {
			num = num * 10 + (token - '0');
			if(indx >= MAX || !isdigit(inp[indx])) {
				nn = (val_node *)malloc(sizeof(val_node));
				(nn->subexpr).data = num;
				(nn->subexpr).left = NULL;
				(nn->subexpr).right = NULL;
				nn->next = NULL;
				push_val(&val, nn);
				num = 0;
			}
		}

		/*if token is opening bracket*/
		else if(token == '('){
			push_opr(&opr, '(');
		}

		/*if token is closing bracket*/
            	else if(token == ')') {
			while(!isEmpty_opr(opr) && peek_opr(opr)!= '(') {
				/*pop 2 operands(big numbers) from value stack*/
				op2 = pop_val(&val);
				op1 = pop_val(&val);
				/*pop operator from character stack*/
				operan = pop_opr(&opr);

				nn = (val_node *)malloc(sizeof(val_node));
				nn->subexpr.data = (int)operan;
				nn->subexpr.left = (&op1->subexpr);
				nn->subexpr.right = (&op2->subexpr);

				/*push nn in value stack*/
				push_val(&val, nn);
			}
			/*if '(', remove it*/
			if(peek_opr(opr) == '(')
				pop_opr(&opr);
			else {
				printf("Syntax Error.\n");
				printf("TYPE: closing brackets are not matched with opening bracket.\n");
				exit(1);
				return;
			}
		}

		/*if token is operrator or anything else*/
		else {
			/*if token is operator*/
			if (isOperator(token)) {
				if(isEmpty_opr(opr))
					push_opr(&opr, token);
				else {
					/*evaluate expression using two operands from value stack and operator from char stack,
					 * considering precedence and associativity*/
					while(!isEmpty_opr(opr) && precedence(peek_opr(opr)) >= precedence(token)){
						op2 = pop_val(&val);
						op1 = pop_val(&val);
						operan = pop_opr(&opr);

						nn = (val_node *)malloc(sizeof(val_node));
                                		nn->subexpr.data = (int)operan;
                                		nn->subexpr.left = (&op1->subexpr);
                                		nn->subexpr.right = (&op2->subexpr);

						push_val(&val, nn);
					}
					push_opr(&opr, token);
				}
			}
			/*error: other operators of symbols are used*/
			else {
				printf("Syntax Error.\n");
				printf("Type: Wrong operator or symbol '%c'\n", token);
				exit(1);
				return;
			}
		}
		token = inp[indx++];
		handle_errors(inp, indx);
	}

	/*evaluate all remaining operations till both stacks become empty*/
	while(!isEmpty_opr(opr)) {
		op2 = pop_val(&val);
		op1 = pop_val(&val);
		operan = pop_opr(&opr);

		if(operan == '('){
			printf("Syntax Error.\nTYPE: Opening brackets are not matched with closing bracket.\n");
			return;
		}

		nn = (val_node *)malloc(sizeof(val_node));
		//nn->subexpr = (tree_node *)malloc(sizeof(tree_node));
		nn->subexpr.data = (int)operan;
		nn->subexpr.left = (&op1->subexpr);
		nn->subexpr.right = (&op2->subexpr);

		push_val(&val, nn);
	}

	nn = pop_val(&val);
	*root = &(nn->subexpr);
	return;
}


// This function receives a node of the syntax tree
// and recursively evaluates it
int eval(tree root) {
	// empty tree
	if (!root)
		return 0;

	// leaf node i.e, an integer
	if (!root->left && !root->right)
		return root->data;

	// Evaluate left subtree
	int l_val = eval(root->left);

	// Evaluate right subtree
	int r_val = eval(root->right);

	int res;
	// Check which operator to apply
	if ((root->data) == '+')
		res = l_val + r_val;

	else if (root->data== '-')
		res = l_val-r_val;

	else if (root->data=='*')
		res = l_val*r_val;

	else res = l_val/r_val;

	printf("\n");
	Inorder(root);
	printf("\n");
	printf("%d %c %d = %d\n", l_val, root->data, r_val, res);

	return res;
}

void compute(tree root) {
	printf("Final Result = %d\n", eval(root));
	return;
}



