/*
GeeksforGeeks - convert sorted DLL to BST

DLL is given 
Node*, Node* left, Node* right

n is given number of nodes - size of DLL 

we have to build BST
*/

int n = findLengthofDLL(Node* head);

Node* temp = head; //head of DLL;

Node* build(int n){
	if(n<=0) return NULL;
	
	Node* leftTree = build(n/2);
	Node* root = temp;
	root->left = leftTree;
	temp = temp->next; // or temp = temp->right
	Node* rightTree = build(n/2-1);
	root->right = rightTree;
	
	return root;
}
