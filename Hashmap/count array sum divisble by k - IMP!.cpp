/*
GeeksforGeeks Sub-Array sum divisible by K, Leetcode 974. Subarray Sums Divisible by K
ques:-
You are given an array A of N positive and/or negative integers and a value K. The task is to find the count of all sub-arrays whose sum is divisible by K.

Example 1:

Input: N = 6, K = 5
       arr[] = {4, 5, 0, -2, -3, 1}
Output: 7
Explanation: There are 7 sub-arrays whose 
is divisible by K {4, 5, 0, -2, -3, 1}, {5}, 
{5, 0}, {5, 0, -2, -3}, {0}, {0, -2, -3} 
and {-2, -3}
Example 2:

Input: N = 6, K = 2
       arr[] = {2, 2, 2, 2, 2, 2}
Output: 21
Explanation: All subarray sums are 
divisible by 7
*/

//gfg solution
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

// Leetcode solution
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int n = nums.size();
        int prefixsum = 0;
        int count = 0;

        unordered_map<int, int> freq;
        freq[0] = 1;

        for (int j = 0; j < n; j++)
        {
            prefixsum += nums[j];
            int num = prefixsum % k;
            if (num < 0)
                num = num + k;
            if (freq.find(num) != freq.end())
                count += freq[num];
            freq[num]++;
        }
        return count;
    }
};