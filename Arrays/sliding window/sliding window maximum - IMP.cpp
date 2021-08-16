/*
leetcode 239. Sliding Window Maximum
ques:-
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
Example 3:

Input: nums = [1,-1], k = 1
Output: [1,-1]
Example 4:

Input: nums = [9,11], k = 2
Output: [11]
Example 5:

Input: nums = [4,-2], k = 2
Output: [4]
*/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n <= 0)
            return {};
        vector<int> prefixmax(n);
        vector<int> suffixmax(n);

        prefixmax[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (i % k == 0)
                prefixmax[i] = nums[i];
            else
                prefixmax[i] = max(prefixmax[i - 1], nums[i]);
        }

        suffixmax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if ((i + 1) % k == 0)
                suffixmax[i] = nums[i];
            else
                suffixmax[i] = max(suffixmax[i + 1], nums[i]);
        }

        vector<int> output;
        for (int i = 0; i < n; i++)
        {
            if (i + k - 1 >= n)
                break;
            output.push_back(max(suffixmax[i], prefixmax[i + k - 1]));
        }

        return output;
    }
};