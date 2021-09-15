/*
leetcode 421. Maximum XOR of Two Numbers in an Array
ques:-
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

 

Example 1:

Input: nums = [3,10,5,25,2,8]
Output: 28
Explanation: The maximum result is 5 XOR 25 = 28.
Example 2:

Input: nums = [0]
Output: 0
Example 3:

Input: nums = [2,4]
Output: 6
Example 4:

Input: nums = [8,10,2]
Output: 10
Example 5:

Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
Output: 127
*/

class Node
{
public:
    int bit;
    vector<Node *> children = vector<Node *>(2);

    Node(int bit)
    {
        this->bit = bit;
    }
};

class Solution
{
public:
    Node *constructTrie(vector<int> &nums)
    {
        Node *root = new Node(2);

        for (int i = 0; i < nums.size(); i++)
        {
            int num = nums[i];
            Node *temp = root;

            for (int j = 31; j >= 0; j--)
            {
                int bit = ((num >> j) & 1);
                if (temp->children[bit] == NULL)
                    temp->children[bit] = new Node(bit);

                temp = temp->children[bit];
            }
        }
        return root;
    }

    int helper(Node *root, int num)
    {
        int output = 0;
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((num >> i) & 1) ? 0 : 1;
            if (temp->children[bit])
            {
                output <<= 1;
                output |= 1;
                temp = temp->children[bit];
            }
            else
            {
                output <<= 1;
                output |= 0;
                temp = temp->children[bit ? 0 : 1];
            }
        }
        return output;
    }

    int findMaximumXOR(vector<int> &nums)
    {
        Node *root = constructTrie(nums);

        int output = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            output = max(output, helper(root, nums[i]));
        }
        return output;
    }
};