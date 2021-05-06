/*
Leetcode 1302 - Deepest Leaves Sum
ques:-
Given the root of a binary tree, return the sum of values of its deepest leaves.

Example 1:

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
Example 2:

Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
*/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        int currsum = 0;
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            currsum = 0;
            while(size--){
                TreeNode* curr = pendingNodes.front();
                pendingNodes.pop();
                currsum+=curr->val;
                if(curr->left)
                    pendingNodes.push(curr->left);
                if(curr->right)
                    pendingNodes.push(curr->right);
            }
        
        }
       return currsum;
    }
};
