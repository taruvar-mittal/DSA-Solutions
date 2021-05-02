/*
GeeksforGeeks - Boundary Traversal of Binary Tree
ques:-
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.
Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Example 1:

Input:
        1
      /   \
     2     3    
   
Output: 1 2 3

Example 2:

Input:
          20
        /   \
       8     22
     /   \    \
    4    12    25
        /  \ 
       10   14 

Output: 20 8 4 10 14 25 22
*/

void leftTraversal(vector<int>& output, Node* root){
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL)
    return;
    
    output.push_back(root->data);
    if(root->left){
        leftTraversal(output,root->left);
    }else
      leftTraversal(output,root->right);
}

void leaves(vector<int> &output,Node* root){
 
  if (root == NULL)
        return;
  
    leaves(output,root->left); 
  
    if(root->left==NULL && root->right==NULL)
     output.push_back(root->data);
  
 
    leaves(output,root->right);
}

void rightTraversal(vector<int> &output,Node* root){
    if(root==NULL)
    return;
    if(root->left==NULL && root->right==NULL)
     return;
     
     if(root->right!=NULL)
     rightTraversal(output,root->right);
     else
     rightTraversal(output,root->left);
     
     output.push_back(root->data);
}

vector <int> printBoundary(Node *root)
{
    vector<int> output;
    leftTraversal(output,root);
    leaves(output,root);
    rightTraversal(output,root->right);
    return output;
}
