/*
Leetcode 99. Recover Binary Search Tree
ques:-
You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

Example 1:

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
Example 2:


Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
*/

// my method 
class Solution {
public:
    void findInorder(TreeNode* root, vector<TreeNode*>& inorder){
        if(root==NULL)
            return;
        
        findInorder(root->left,inorder);
        inorder.push_back(root);
        findInorder(root->right,inorder);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorder;
        findInorder(root,inorder);
        
        int left = 0;
        int right = inorder.size()-1;
        while(left<inorder.size()&&inorder[left+1]->val>inorder[left]->val)
            left++;
        while(right>0&&inorder[right-1]->val<inorder[right]->val)
            right--;
        
        swap(inorder[left]->val,inorder[right]->val);
        
    }
};
