/*
leetcode 905. Sort Array By Parity
ques:-
Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

Return any array that satisfies this condition.

Example 1:

Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
Example 2:

Input: nums = [0]
Output: [0]
*/

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0, j = 0;
        while (j < n)
        {
            if (arr[j] % 2 == 0)
            {
                swap(arr[i], arr[j]);
                i++;
                j++;
            }
            else
                j++;
        }

        return arr;
    }
};