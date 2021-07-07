/*
Leetcode 300. Longest Increasing Subsequence
ques:-
Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
*/

class Solution
{
public:
    // O(n^2)
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> lis(n,1);
    //     for(int i=1;i<n;i++){
    //         int curr = lis[i];
    //         for(int j=0;j<i;j++){
    //             if(nums[j]<nums[i])
    //              curr = max(curr,lis[i]+lis[j]);
    //         }
    //         lis[i] = curr;
    //     }
    //     int output = INT_MIN;
    //     for(int i=0;i<n;i++){
    //         output = max(output,lis[i]);
    //     }
    //     return output;
    // }

    // O(nlogn)
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> lis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int low = 0;
            int high = ans;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (nums[i] > lis[mid])
                    low = mid + 1;
                else
                    high = mid;
            }
            lis[low] = nums[i];
            if (low == ans)
                ans++;
        }

        return ans;
    }
};