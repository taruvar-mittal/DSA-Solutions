/*
GeeksforGeeks - construct BST from postorder
ques:-
Given postorder traversal of a Binary Search Tree, you need to construct a BST from postorder traversal. The output will be inorder traversal of the constructed BST.

Example 1:

Input:
6
1 7 5 50 40 10

Output:
1 5 7 10 40 50

Explanation:
Testcase 1: The BST for the given post order traversal is:


Thus the inorder traversal of BST is: 1 5 7 10 40 50.
*/

Node* build(int post[], int& i, int left, int right){
    if(i<0)
    return NULL;
    
    if(post[i]<left || post[i]>right)
      return NULL;
      
      Node* root = new Node( post[i]);
      i--;
      
      root->right = build(post,i,root->data+1,right);
      root->left = build(post,i,left,root->data-1);
      return root;
}
Node *constructTree (int post[], int size)
{
    int i = size-1;
    int left = INT_MIN;
    int right = INT_MAX;
    return build(post,i,left,right);
//code here
}

