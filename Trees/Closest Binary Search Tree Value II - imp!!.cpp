/*
Lintcode 901 · Closest Binary Search Tree Value II
ques:-
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Example
Example 1:

Input:
{1}
0.000000
1
Output:
[1]
Explanation：
Binary tree {1},  denote the following structure:
 1
Example 2:

Input:
{3,1,4,#,2}
0.275000
2
Output:
[1,2]
Explanation：
Binary tree {3,1,4,#,2},  denote the following structure:
  3
 /  \
1    4
 \
  2
  */

class Solution
{
public:
    stack<int> smaller;
    stack<int> greater;

    void fillsmaller(TreeNode *root, double target)
    {
        if (root == NULL)
            return;

        fillsmaller(root->left, target);
        if (root->val <= target)
            smaller.push(root->val);
        fillsmaller(root->right, target);
    }

    void fillgreater(TreeNode *root, double target)
    {
        if (root == NULL)
            return;

        fillgreater(root->right, target);
        if (root->val > target)
            greater.push(root->val);
        fillgreater(root->left, target);
    }

    vector<int> closestKValues(TreeNode *root, double target, int k)
    {
        // write your code here
        fillsmaller(root, target);
        fillgreater(root, target);

        vector<int> output;
        for (int i = 0; i < k; i++)
        {
            if (smaller.empty())
            {
                output.push_back(greater.top());
                greater.pop();
            }
            else if (greater.empty())
            {
                output.push_back(smaller.top());
                smaller.pop();
            }
            else
            {
                if (abs(double(target - smaller.top())) < abs(double(target - greater.top())))
                {
                    output.push_back(smaller.top());
                    smaller.pop();
                }
                else
                {
                    output.push_back(greater.top());
                    greater.pop();
                }
            }
        }
        return output;
    }
};