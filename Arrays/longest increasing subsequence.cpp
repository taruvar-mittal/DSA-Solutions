/*
Leetcode 300 - Longest increasing subsequence
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

class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        int lis[n];
        
        for(int i=0;i<n;i++){
            lis[i] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i] && lis[j]+1>lis[i])
                    lis[i] = lis[j]+1;
            }
        }
        
        int ans = lis[0];
        for(int i=1;i<n;i++){
            ans = max(ans,lis[i]);
        }
        return ans;
    }
};
