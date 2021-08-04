/*
Leetcode 90. Subsets II
ques:-
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        output.push_back({});
        set<vector<int>> s;
        s.insert({});

        for (auto n : nums)
        {
            int size = output.size();
            for (int i = 0; i < size; i++)
            {
                vector<int> curr = output[i];
                curr.push_back(n);
                if (s.find(curr) == s.end())
                {
                    output.push_back(curr);
                    s.insert(curr);
                }
            }
        }
        return output;
    }
};