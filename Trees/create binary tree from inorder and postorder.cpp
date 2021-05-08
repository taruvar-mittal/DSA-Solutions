/*
Leetcode 106. - create binary tree from inorder and postorder traversal
ques:-
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return
Example 1:

Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n==0) return nullptr;
        if(n==1)
            return new TreeNode(inorder[0]);
        return helper(inorder, 0, n-1, postorder, 0, n-1);
    }
    
    TreeNode* helper(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe){
        if(is>ie || ps>pe)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[pe]);
        
        int marker = 0;
        while(inorder[marker]!=root->val){
            marker++;
        }
        
        root->left=helper(inorder, is, is+marker-1, postorder, ps, ps+marker-is-1);
        root->right = helper(inorder, marker+1, ie, postorder, ps+marker-is, pe-1);
        return root;
    }
};
