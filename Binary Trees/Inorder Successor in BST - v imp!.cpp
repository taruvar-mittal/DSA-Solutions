/*
Lintcode - Inorder Successor in BST
link - https://www.lintcode.com/problem/inorder-successor-in-bst/
ques:-
Given a binary search tree (See Definition) and a node in it, find the in-order successor of that node in the BST.

If the given node has no in-order successor in the tree, return null.

It's guaranteed p is one node in the given tree. (You can directly compare the memory address to find p)

Example
Example 1:

Input: {1,#,2}, node with value 1
Output: 2
Explanation:
  1
   \
    2
Example 2:

Input: {2,1,3}, node with value 1
Output: 2
Explanation: 
    2
   / \
  1   3
*/
  
class Solution {
public:
    TreeNode* storedNode = NULL;
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root==NULL)
        return root;

        if(root==p){
            if(root->right!=NULL){
               TreeNode* ans = root->right;
               while(ans->left)
                 ans = ans->left;

                 return ans;
            }else
             return storedNode;
        }

        if(p->val>root->val)
          return inorderSuccessor(root->right,p);
        else{
            storedNode = root;
            return inorderSuccessor(root->left,p);
        }
    }
};
  
