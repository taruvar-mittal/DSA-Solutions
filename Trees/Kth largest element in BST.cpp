/*
geeksforGeeks - Kth largest element in BST
ques:-
Given a Binary search tree. Your task is to complete the function which will return the Kth largest element without doing any modification in Binary Search Tree.


Example 1:

Input:
      4
    /   \
   2     9
k = 2 
Output: 4

Example 2:

Input:
       9
        \ 
          10
K = 1
Output: 10
*/

class Solution
{
    public:
    void findInorder(Node* root, vector<int>& inorder){
        if(root==NULL)
        return;
        
        findInorder(root->right,inorder);
        inorder.push_back(root->data);
        findInorder(root->left,inorder);
    }
    
    int kthLargest(Node *root, int K)
    {
        vector<int> inorder;
        findInorder(root,inorder);
        return inorder[K-1];
    }
};
