#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int data){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    
    return p;
}

Node *findLCA(Node *root, Node *a, Node *b) {
	if(root == NULL)
		return NULL;
	else if(root == a || root == b)
		return root;
	Node *left = findLCA(root->left, a, b);
	Node *right = findLCA(root->right, a, b);
	if(left && right)
		return root;
	else
		return left?left:right;
}    

int main(void) {
	Node *root = createNode(10);
	root->left = createNode(20);
	root->right = createNode(30);
	root->left->left = createNode(40);
	root->right->left = createNode(50);
	root->right->left->left = createNode(60);
	root->right->left->left->right = createNode(70);
	root->right->right = createNode(80);

	Node *lca = findLCA(root, root->right->left->left->right, root->right->right);
	if(!lca) {
		printf("Tree is empty\n");
	}
	else {
		printf("Ancestor is: %d\n", lca->data);
	}
	return 0;
}


