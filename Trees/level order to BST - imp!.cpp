/*
GeeksforGeeks - level order to BST
ques:-
Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List strating from the left most leaf. Modify the original tree to make the DLL thus removing the leaf nodes from the tree. Consider the left and right pointers of the tree to be the previous and next pointer of the DLL respectively.

Example 1:

Input :
        1
      /   \
     2     3
    / \   / \
   4   5 6   7    

Output: 
Modified Tree :
        1
      /   \
     2     3

Doubly Link List :
4 <-> 5 <-> 6 <-> 7

Explanation:
The leaf nodes are modified to form the DLL 
in-place. Thus their links are removed from 
the tree.
Example 2:

Input :
        1
      /   \
     2     3
    / \   
   4   5 

Output: 
Modified Tree :
        1
      /   
     2    

Doubly Link List :
4 <-> 5 <-> 3
*/

Node* levelOrder(Node* root, int val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }
    
    if(val<=root->data)
      root->left = levelOrder(root->left,val);
    else
      root->right = levelOrder(root->right,val);
      
      return root;
}
Node* constructBst(int arr[], int n)
{
    if(n==0)
    return NULL;
    
    Node* root = NULL;
    
    for(int i=0;i<n;i++){
        root = levelOrder(root,arr[i]);
    }
    return root;
}

