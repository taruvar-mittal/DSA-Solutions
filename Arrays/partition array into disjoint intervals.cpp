/*
leetcode 915. Partition Array into Disjoint Intervals
ques:-
Given an integer array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.

Test cases are generated such that partitioning exists.

 Example 1:

Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
*/

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 1)
            return 0;

        int currmax = nums[0];
        int nextmax = nums[0];
        int pidx = 0;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] >= currmax)
            {
                nextmax = max(nums[i], nextmax);
            }
            else
            {
                currmax = nextmax;
                pidx = i;
            }
        }

        return pidx + 1;
    }
};