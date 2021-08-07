/*
Leetcode 169. Majority Element
ques:-
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int val = nums[0];
        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (val == nums[i])
                count++;
            else
            {
                if (count == 0)
                {
                    val = nums[i];
                    count++;
                }
                else
                    count--;
            }
        }

        return val;
    }
};