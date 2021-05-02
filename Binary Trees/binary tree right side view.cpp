/*
Leetcode 199 - Binary Tree Right Side View
ques:-
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        if(root==NULL)
            return output;
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            while(size>0){
                TreeNode* curr = pendingNodes.front();
                pendingNodes.pop();
                size--;
                if(size==0)
                    output.push_back(curr->val);
                if(curr->left)
                    pendingNodes.push(curr->left);
                if(curr->right)
                    pendingNodes.push(curr->right);
            }
        }
        return output;
    }
};
