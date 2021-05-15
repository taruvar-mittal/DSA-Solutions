/*
Leetcode 1110. Delete Nodes And Return Forest
ques:-
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

Example 1:
Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
*/

class Solution
{
public:
    vector<TreeNode *> output;
    void helper(TreeNode *&root, vector<int> &to_delete)
    {
        if (root == NULL)
            return;

        helper(root->left, to_delete);
        helper(root->right, to_delete);
        if (find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end())
        {
            if (root->left)
                output.push_back(root->left);
            if (root->right)
                output.push_back(root->right);
            root = NULL;
        }
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        if (root == NULL)
            return output;
        helper(root, to_delete);
        if (root)
            output.push_back(root);
        return output;
    }
};