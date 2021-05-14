/*
Leetcode 222. Count Complete Tree Nodes
ques:-
Given the root of a complete binary tree, return the number of the nodes in the tree.

According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6
Example 2:

Input: root = []
Output: 0
Example 3:

Input: root = [1]
Output: 1
*/

class Solution {
public:
    int leftcount(TreeNode* root){
        if(root==NULL)
            return 0;
        
        return 1+leftcount(root->left);
    }
    int rightcount(TreeNode* root){
        if(root==NULL)
            return 0;
        
        return 1+rightcount(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        int lc = leftcount(root);
        int rc = rightcount(root);
        if(lc==rc){
            return ((1<<lc)-1);
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};