/*
Leetcode 229. Majority Element II
ques:-
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Follow-up: Could you solve the problem in linear time and in O(1) space?

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 0)
            return {};
        int val1 = nums[0];
        int count1 = 1;
        int val2 = nums[0];
        int count2 = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] == val1)
                count1++;
            else if (nums[i] == val2)
                count2++;
            else if (count1 == 0)
            {
                val1 = nums[i];
                count1++;
            }
            else if (count2 == 0)
            {
                val2 = nums[i];
                count2++;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        count1 = 0;
        count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == val1)
                count1++;
            else if (nums[i] == val2)
                count2++;
        }

        vector<int> output;
        if (count1 > n / 3)
            output.push_back(val1);
        if (count2 > n / 3)
            output.push_back(val2);

        return output;
    }
};