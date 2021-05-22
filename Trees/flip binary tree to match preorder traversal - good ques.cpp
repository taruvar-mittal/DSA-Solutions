/*
Leetcode 971. Flip Binary Tree To Match Preorder Traversal
ques:-
You are given the root of a binary tree with n nodes, where each node is uniquely assigned a value from 1 to n. You are also given a sequence of n values voyage, which is the desired pre-order traversal of the binary tree.

Any node in the binary tree can be flipped by swapping its left and right subtrees. For example, flipping node 1 will have the following effect:

Flip the smallest number of nodes so that the pre-order traversal of the tree matches voyage.

Return a list of the values of all flipped nodes. You may return the answer in any order. If it is impossible to flip the nodes in the tree to make the pre-order traversal match voyage, return the list [-1].

Example 1:

Input: root = [1,2], voyage = [2,1]
Output: [-1]
Explanation: It is impossible to flip the nodes such that the pre-order traversal matches voyage.
Example 2:

Input: root = [1,2,3], voyage = [1,3,2]
Output: [1]
Explanation: Flipping node 1 swaps nodes 2 and 3, so the pre-order traversal matches voyage.
Example 3:

Input: root = [1,2,3], voyage = [1,2,3]
Output: []
Explanation: The tree's pre-order traversal already matches voyage, so no nodes need to be flipped.
*/

class Solution
{
public:
    vector<int> output;

    bool check(TreeNode *root, vector<int> &voyage, int &idx)
    {
        if (root == NULL)
            return true;

        if (root->val != voyage[idx++])
            return false;
        if (root->left != NULL && root->left->val != voyage[idx])
        {
            if (root->right != NULL && root->right->val == voyage[idx])
            {
                output.push_back(root->val);
                swap(root->left, root->right);
            }
            else
                return false;
        }
        return check(root->left, voyage, idx) && check(root->right, voyage, idx);
    }

    vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
    {
        int idx = 0;
        if (check(root, voyage, idx))
            return output;

        return {-1};
    }
};