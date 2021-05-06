/*
GeeksforGeeks
ques:- 
Given a Binary Tree of size N. Find the sum of all the leaf nodes that are left child of their parent of the given binary tree.

Example 1:

Input:
       1
     /   \
    2     3
Output: 2

Example 2:

Input : 
         1
        /  \
       2    3
     /  \     \
    4    5     8 
  /  \        /  \
 7    2      6    9
Output: 13
Explanation:
sum = 6 + 7 = 13
*/

bool checkisleaf(Node* node){
    if(node==NULL)
    return false;
    
    if(node->left==NULL && node->right==NULL)
    return true;
    
    return false;
}

int leftLeavesSum(Node *root)
{
    int sum = 0;
    if(root==NULL)
    return 0;
    
    if(checkisleaf(root->left))
      sum+=root->left->data;
    else
       sum+=leftLeavesSum(root->left);
      
      sum+=leftLeavesSum(root->right);
      
      return sum;
}
