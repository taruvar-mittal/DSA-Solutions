/*
Leetcode 977. Squares of a Sorted Array
ques:-
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> output(n);

        int i = 0, j = n - 1;
        for (int k = n - 1; k >= 0; k--)
        {
            if (abs(arr[i]) > abs(arr[j]))
            {
                output[k] = arr[i] * arr[i];
                i++;
            }
            else
            {
                output[k] = arr[j] * arr[j];
                j--;
            }
        }

        return output;
    }
};
