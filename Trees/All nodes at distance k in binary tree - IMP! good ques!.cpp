/*
Leetcode 863. All Nodes Distance K in Binary Tree
ques:-
We are given a binary tree (with root node root), a target node, and an integer value k.

Return a list of the values of all nodes that have a distance k from the target node.  The answer can be returned in any order.

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.

Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.
*/

class Solution
{
public:
    vector<int> output;

    void addNodes(TreeNode *root, int k)
    {
        if (root == NULL)
            return;
        if (k < 0)
            return;
        if (k == 0)
        {
            output.push_back(root->val);
            return;
        }
        addNodes(root->left, k - 1);
        addNodes(root->right, k - 1);
    }

    int findTarget(TreeNode *root, TreeNode *target, int k)
    {
        if (root == NULL)
            return -1;

        if (root == target)
        {
            addNodes(root->left, k - 1);
            addNodes(root->right, k - 1);
            return k - 1;
        }

        int l = findTarget(root->left, target, k);
        if (l >= 0)
        {
            if (l == 0)
            {
                output.push_back(root->val);
                return l - 1;
            }
            else
            {
                addNodes(root->right, l - 1);
                return l - 1;
            }
        }

        int r = findTarget(root->right, target, k);
        if (r >= 0)
        {
            if (r == 0)
            {
                output.push_back(root->val);
                return r - 1;
            }
            else
            {
                addNodes(root->left, r - 1);
                return r - 1;
            }
        }
        return -1;
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        if (K == 0)
            return {target->val};

        findTarget(root, target, K);
        return output;
    }
};