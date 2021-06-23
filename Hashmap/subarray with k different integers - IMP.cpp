/*
Leetcode 992. Subarrays with K Different Integers
ques:-
Given an array nums of positive integers, call a (contiguous, not necessarily distinct) subarray of nums good if the number of different integers in that subarray is exactly k.

(For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)

Return the number of good subarrays of nums.

Example 1:

Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
Example 2:

Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/

class Solution
{
public:
    int helper(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int i = 0, j = 0, count = 0;
        while (j < nums.size())
        {
            mp[nums[j]]++;
            while (i <= j && mp.size() > k)
            {

                if (mp[nums[i]] == 1)
                    mp.erase(nums[i]);
                else
                    mp[nums[i]]--;
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return helper(nums, k) - helper(nums, k - 1);
    }
};