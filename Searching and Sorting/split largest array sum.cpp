/*
Leetcode 410. Split Array Largest Sum
ques:-
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18
Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], m = 2
Output: 9
Example 3:

Input: nums = [1,4,4], m = 3
Output: 4
*/

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        int low = nums[0];
        int high = nums[0];
        for (int i = 1; i < n; i++)
        {
            low = max(low, nums[i]);
            high += nums[i];
        }
        int ans = high;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int numsubarrays = 0;
            int i = 0;
            while (i < n)
            {
                int currsum = 0;
                while (i < n && currsum + nums[i] <= mid)
                {
                    currsum += nums[i];
                    i++;
                }
                numsubarrays++;
            }
            if (numsubarrays <= m)
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else if (numsubarrays > m)
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};