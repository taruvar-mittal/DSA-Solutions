/*
Leetcode 747. Largest Number At Least Twice of Others
ques:-
You are given an integer array nums where the largest integer is unique.

Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.

Example 1:

Input: nums = [3,6,1,0]
Output: 1
Explanation: 6 is the largest integer.
For every other number in the array x, 6 is at least twice as big as x.
The index of value 6 is 1, so we return 1.
Example 2:

Input: nums = [1,2,3,4]
Output: -1
Explanation: 4 is less than twice the value of 3, so we return -1.
Example 3:

Input: nums = [1]
Output: 0
Explanation: 1 is trivially at least twice the value as any other number because there are no other numbers.
*/

class Solution
{
public:
    int dominantIndex(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 0)
            return -1;
        if (n == 1)
            return 0;
        int firstmax = INT_MIN;
        int index = -1;
        int secondmax = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > firstmax)
            {
                secondmax = firstmax;
                firstmax = arr[i];
                index = i;
            }
            else if (arr[i] > secondmax)
                secondmax = arr[i];
        }

        if (firstmax >= 2 * secondmax)
            return index;
        else
            return -1;
    }
};