/*
leetcode 1382 - Balance a BST
ques:-
Given a binary search tree, return a balanced binary search tree with the same node values.

A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.

If there is more than one answer, return any of them.

Example 1:

Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct
*/

class Solution {
public:
    void findInorder(TreeNode* root, vector<int>& inorder){
        if(root==NULL)
            return;
        findInorder(root->left,inorder);
        inorder.push_back(root->val);
        findInorder(root->right,inorder);
    }
    
    TreeNode* findTree(vector<int>& inorder, int start, int end){
        if(start>end)
            return NULL;
        
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left=findTree(inorder,start,mid-1);
        root->right = findTree(inorder,mid+1,end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        findInorder(root,inorder);
        
        return findTree(inorder,0,inorder.size()-1);
    }
};
