/*
Leetcode 560. Subarray Sum Equals K
ques:-
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/

// O(2n)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = nums[i - 1] + nums[i];
        }
        unordered_map<int, int> freq;
        freq[0]++;
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            int num = nums[j] - k;
            if (freq.find(num) != freq.end())
                count += freq[num];
            freq[nums[j]]++;
        }
        return count;
    }
};

//O(n)
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        int prefixsum = 0;
        unordered_map<int, int> freq;
        freq[0]++;
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            prefixsum += nums[j];
            int num = prefixsum - k;
            if (freq.find(num) != freq.end())
                count += freq[num];
            freq[prefixsum]++;
        }
        return count;
    }
};