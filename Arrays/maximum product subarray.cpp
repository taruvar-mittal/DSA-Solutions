/*
leetcode 152. Maximum Product Subarray
ques:-
Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.

It is guaranteed that the answer will fit in a 32-bit integer.

A subarray is a contiguous subsequence of the array.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 
 */

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int currprod = 1;
        int overallprod = INT_MIN;

        bool flag = false;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                currprod = 1;
                flag = true;
                continue;
            }

            currprod *= nums[i];
            overallprod = max(overallprod, currprod);
        }

        currprod = 1;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                currprod = 1;
                flag = true;
                continue;
            }

            currprod *= nums[i];
            overallprod = max(overallprod, currprod);
        }

        if (flag)
            return max(overallprod, 0);
        else
            return overallprod;
    }
};