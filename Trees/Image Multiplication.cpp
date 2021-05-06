/*
GeeksforGeeks - Image Multiplication
ques:-
You are given a binary tree. Your task is pretty straightforward. You have to find the sum of the product of each node and its mirror image (The mirror of a node is a node which exists at the mirror position of the node in opposite subtree at the root.). Don’t take into account a pair more than once. The root node is the mirror image of itself.

Example 1:

Input:
      4         
    /    \
   5      6
Output:
46
Explanation:
Sum = (4*4) + (5*6) = 46
Example 2:

Input:
                       1                 
                   /        \
                 3            2
                  /  \         /  \
              7     6       5    4
            /   \    \     /  \    \
          11    10    15  9    8    12
Output:
332
Explanation:
Sum = (1*1) + (3*2) + (7*4) + (6*5) + (11*12) + (15*9) = 332
*/

const unsigned int M = 1000000007;
class Solution
{
    public:
      long long ans = 0;
    void helper(Node* root1,Node* root2){
        if(root1==NULL || root2==NULL)
        return;
        
       ans=(ans%M+(root1->data*root2->data)%M)%M;
        helper(root1->left,root2->right);
        helper(root1->right,root2->left);
    }
    
    long long imgMultiply(Node *root)
    {
      ans=(ans%M+(root->data*root->data)%M)%M;
        helper(root->left,root->right);
        return ans;
    }
};
