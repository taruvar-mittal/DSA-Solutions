/*
Leetcode 768. Max Chunks To Make Sorted II
ques:-
You are given an integer array arr.

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.

Example 1:

Input: arr = [5,4,3,2,1]
Output: 1
Explanation:
Splitting into two or more chunks will not return the required result.
For example, splitting into [5, 4], [3, 2, 1] will result in [4, 5, 1, 2, 3], which isn't sorted.
Example 2:

Input: arr = [2,1,3,4,4]
Output: 4
Explanation:
We can split into two chunks, such as [2, 1], [3, 4, 4].
However, splitting into [2, 1], [3], [4], [4] is the highest number of chunks possible.
*/

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefixmax(n, INT_MIN);
        vector<int> suffixmin(n, INT_MAX);

        prefixmax[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefixmax[i] = max(prefixmax[i - 1], arr[i]);
        }

        suffixmin[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffixmin[i] = min(suffixmin[i + 1], arr[i]);
        }

        int chunks = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (prefixmax[i] <= suffixmin[i + 1])
                chunks++;
        }

        return chunks + 1;
    }
};