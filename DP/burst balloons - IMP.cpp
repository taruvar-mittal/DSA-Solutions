/*
Leetcode 312. Burst Balloons
ques:-
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
*/

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++)
        {
            arr[i + 1] = nums[i];
        }
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        return burst(arr, 0, n + 1, dp);
    }

    int burst(vector<int> &arr, int left, int right, vector<vector<int>> &dp)
    {
        for (int gap = 2; gap < arr.size(); gap++)
        {
            for (int left = 0; left < arr.size() - gap; left++)
            {
                int right = left + gap;
                for (int i = left + 1; i < right; i++)
                {
                    dp[left][right] = max(dp[left][right], dp[left][i] + dp[i][right] + arr[i] * arr[left] * arr[right]);
                }
            }
        }
        return dp[0][arr.size() - 1];
    }
};