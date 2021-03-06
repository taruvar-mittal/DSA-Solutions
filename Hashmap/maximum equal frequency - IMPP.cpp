/*
Leetcode 1224. Maximum Equal Frequency
ques:-
Given an array nums of positive integers, return the longest possible length of an array prefix of nums, such that it is possible to remove exactly one element from this prefix so that every number that has appeared in it will have the same number of occurrences.

If after removing one element there are no remaining elements, it's still considered that every appeared number has the same number of ocurrences (0).


Example 1:

Input: nums = [2,2,1,1,5,3,3,5]
Output: 7
Explanation: For the subarray [2,2,1,1,5,3,3] of length 7, if we remove nums[4]=5, we will get [2,2,1,1,3,3], so that each number will appear exactly twice.
Example 2:

Input: nums = [1,1,1,2,2,2,3,3,3,4,4,4,5]
Output: 13
Example 3:

Input: nums = [1,1,1,2,2,2]
Output: 5
Example 4:

Input: nums = [10,2,8,9,3,8,1,5,2,3,7,6]
Output: 8
*/

class Solution
{
public:
    int maxEqualFreq(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        unordered_map<int, int> freq;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            freq[mp[nums[i]]]++;

            if (i < nums.size() - 1 && ((freq[mp[nums[i]]] * mp[nums[i]]) == (i + 1)))
            {
                ans = max(ans, i + 2);
            }
            else if ((freq[mp[nums[i]]] * mp[nums[i]]) == (i))
            {
                ans = max(ans, i + 1);
            }
        }

        return ans;
    }
};