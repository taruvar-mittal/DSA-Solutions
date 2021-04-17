/*
GeeksForGeeks
ques:- Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.
*/

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    int helper(Node* root){
        if(root==NULL)
          return 0;
        
        int temp = root->data;
        root->data = helper(root->left)+helper(root->right);
        return temp+root->data;
    }
  
    void toSumTree(Node *node)
    {
       int x = helper(node);
    }
};
