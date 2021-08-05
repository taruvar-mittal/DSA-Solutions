/*
Leetcode Path Sum II
ques:-
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.

 

Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []
*/

class Solution
{
public:
    vector<vector<int>> output;

    void helper(TreeNode *root, int targetSum, vector<int> &curr)
    {
        if (root == NULL)
            return;
        curr.push_back(root->val);
        if (root->left == NULL && root->right == NULL && targetSum == root->val)
            output.push_back(curr);
        helper(root->left, targetSum - root->val, curr);
        helper(root->right, targetSum - root->val, curr);
        curr.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> curr = {};
        helper(root, targetSum, curr);
        return output;
    }
};