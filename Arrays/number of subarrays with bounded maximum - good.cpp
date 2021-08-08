/*
Leetcode 795. Number of Subarrays with Bounded Maximum
ques:-
Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].

The test cases are generated so that the answer will fit in a 32-bit integer.

Example 1:

Input: nums = [2,1,4,3], left = 2, right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Example 2:

Input: nums = [2,9,2,5,6], left = 2, right = 8
Output: 7
*/

class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &arr, int left, int right)
    {
        int n = arr.size();
        int prevvalid = 0;
        int ans = 0;
        int i = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > right)
            {
                prevvalid = 0;
                i = j + 1;
            }
            else if (arr[j] < left)
            {
                ans += prevvalid;
            }
            else
            {
                ans += j - i + 1;
                prevvalid = j - i + 1;
            }
        }

        return ans;
    }
};