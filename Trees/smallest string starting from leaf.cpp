/*
Leetcode 988. Smallest String Starting From Leaf
ques:-
Given the root of a binary tree, each node has a value from 0 to 25 representing the letters 'a' to 'z': a value of 0 represents 'a', a value of 1 represents 'b', and so on.

Find the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

(As a reminder, any shorter prefix of a string is lexicographically smaller: for example, "ab" is lexicographically smaller than "aba".  A leaf of a node is a node that has no children.)

Example 1:

Input: [0,1,2,3,4,3,4]
Output: "dba"
Example 2:

Input: [25,1,3,1,3,0,2]
Output: "adz"
Example 3:

Input: [2,2,1,null,1,0,null,0]
Output: "abc"
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
class Solution
{
public:
    void dfs(TreeNode *root, string s, vector<string> &output)
    {
        if (root == NULL)
            return;

        s += root->val + 'a';
        if (root->left == NULL && root->right == NULL)
        {
            reverse(s.begin(), s.end());
            output.push_back(s);
        }
        dfs(root->left, s, output);
        dfs(root->right, s, output);
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string s = "";
        vector<string> output;
        dfs(root, s, output);
        sort(output.begin(), output.end());
        return output[0];
    }
};