/*
Leetcode 81. Search in Rotated Sorted Array II
ques:-
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/

class Solution {
public:
    int searchnum(vector<int> &nums, int low, int high, int target)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
    
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<high){
            while(low<n-1&&nums[low]==nums[low+1]) low++;
            while(high>0&&nums[high]==nums[high-1]) high--;
            if(low>high) break;
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[high])
                low = mid+1;
            else
                high = mid;
        }
        int pivot = low;
        int x = searchnum(nums, 0, pivot - 1, target);
        int y = searchnum(nums, pivot, n-1, target);
        
        return !(x==-1&&y==-1);
    }
};