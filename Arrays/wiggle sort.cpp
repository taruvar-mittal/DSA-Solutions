/*
lintcode 508 · Wiggle Sort
ques:-
Description
Given an unsorted array nums, reorder it in-place such that

nums[0] <= nums[1] >= nums[2] <= nums[3]....
Please sort the array in place and do not define additional arrays.

Example
Example 1:

Input: [3, 5, 2, 1, 6, 4]
Output: [1, 6, 2, 5, 3, 4]
Explanation: This question may have multiple answers, and [2, 6, 1, 5, 3, 4] is also ok.
Example 2:

Input: [1, 2, 3, 4]
Output: [1, 4, 2, 3]
*/

class Solution
{
public:
    void wiggleSort(vector<int> &arr)
    {
        int n = arr.size();
        bool temp = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (temp)
            {
                if (!(arr[i] <= arr[i + 1]))
                    swap(arr[i], arr[i + 1]);
            }
            else
            {
                if (!(arr[i] >= arr[i + 1]))
                    swap(arr[i], arr[i + 1]);
            }

            temp = !temp;
        }
    }
};