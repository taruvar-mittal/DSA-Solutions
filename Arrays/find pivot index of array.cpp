/* 
Leetcode 724 - find pivot index | find equilibrium index of an array
ques:- Given an array of integers nums, calculate the pivot index of this array.

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

Return the leftmost pivot index. If no such index exists, return -1.

Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n<1)
            return -1;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
      
        for(int i=0;i<n;i++){
            if(i==0){
                if(nums[n-1]==nums[0])
                    return 0;
            }else
            if(nums[i-1]==nums[n-1]-nums[i])
                return i;
        }
        return -1;
    }
};


