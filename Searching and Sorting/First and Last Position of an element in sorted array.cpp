/*
Leetcode - First and last position of element in sorted array
done using binary search - O(nlogn)
ques:-
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                int first = mid;
                while(first>=0 && nums[first]==target)
                    first--;
                int last = mid;
                while(last<n && nums[last]==target)
                    last++;
                return {first+1,last-1};
            }else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return {-1,-1};
    }
};
