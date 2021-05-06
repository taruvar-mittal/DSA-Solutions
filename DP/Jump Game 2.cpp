/*
Leetcode 45 - Jump Game 2
ques:-
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n,INT_MAX);
        steps[0] = 0;
        for(int i=0;i<n;i++){
            for(int j=min(n-1,i+nums[i]);j>i;j--){
                if(steps[j]>steps[i]+1)
                    steps[j] = steps[i]+1;
                else
                    break;
            }
        }
        return steps[n-1];
    }
};
