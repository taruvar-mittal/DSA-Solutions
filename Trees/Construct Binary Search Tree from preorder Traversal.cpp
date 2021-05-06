/*
Leetcode 1008 = Construct Binary Search Tree from preorder Traversal
ques:-
Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.

A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.

A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:

Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]
Example 2:

Input: preorder = [1,3]
Output: [1,null,3]
*/

 */
 
class Solution {
public:
    TreeNode* helper(vector<int>& preorder,int start, int end){
        if(start>end)
            return NULL;
        
        int left = start;
        while(left+1<=end && preorder[left+1]<preorder[start])
            left++;
        
        TreeNode* root = new TreeNode(preorder[start]);
        
        root->left = helper(preorder,start+1,left);
        root->right = helper(preorder,left+1,end);
        return root;
        
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = helper(preorder,0,preorder.size()-1);
        return root;
    }
};
