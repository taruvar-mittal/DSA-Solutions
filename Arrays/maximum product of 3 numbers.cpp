/*
Leetcode 628. Maximum Product of Three Numbers
ques:-
Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:

Input: nums = [1,2,3]
Output: 6
Example 2:

Input: nums = [1,2,3,4]
Output: 24
Example 3:

Input: nums = [-1,-2,-3]
Output: -6
*/

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        return max(nums[n - 1] * nums[0] * nums[1], nums[n - 1] * nums[n - 2] * nums[n - 3]);
    }
};