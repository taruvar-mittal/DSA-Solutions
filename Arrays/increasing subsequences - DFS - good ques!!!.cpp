/*
Leetcode 491. Increasing Subsequences
ques:-
Given an integer array nums, return all the different possible increasing subsequences of the given array with at least two elements. You may return the answer in any order.

The given array may contain duplicates, and two equal integers should also be considered a special case of increasing sequence.

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]]
*/

class Solution
{
public:
    set<vector<int>> output;
    vector<int> temp;

    void dfs(vector<int> &nums, int idx, int last)
    {

        if (temp.size() > 1)
        {
            output.insert(temp);
        }

        for (int i = idx; i < nums.size(); i++)
        {
            if (nums[i] >= last)
            {
                temp.push_back(nums[i]);
                dfs(nums, i + 1, nums[i]);
                temp.pop_back();
            }
            else
            {
                dfs(nums, i + 1, last);
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0, INT_MIN);
        vector<vector<int>> result(output.begin(), output.end());
        return result;
    }
};