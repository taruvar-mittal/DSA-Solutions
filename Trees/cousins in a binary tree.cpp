/*
Leetcode 993. Cousins in Binary Tree
ques:-
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
*/

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL)
            return false;
        queue<pair<TreeNode*, TreeNode*>> q; 
            q.push({root, NULL});
        while(!q.empty())
        {
            TreeNode *x_parent = nullptr, *y_parent = nullptr;
            int sz = q.size();
            for(int i = 0; i < sz; ++i)
            {
                auto [node, parent] = q.front(); 
                q.pop();
                if(node->val == x) x_parent = parent;
                else if(node->val == y) y_parent = parent;
                if(node->left) q.push({node->left, node});
                if(node->right) q.push({node->right, node});
            }
            if(x_parent || y_parent) return x_parent && y_parent && x_parent != y_parent ;
        }
        return false;
    }
};
