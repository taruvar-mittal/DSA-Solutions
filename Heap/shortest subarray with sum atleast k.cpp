/*
Leetcode 862. Shortest Subarray with Sum at Least K
ques:-
Return the length of the shortest, non-empty, contiguous subarray of nums with sum at least k.

If there is no non-empty subarray with sum at least k, return -1.

Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
*/

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        int currsum = 0;
        int output = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            currsum += nums[i];
            if (currsum >= k)
            {
                output = min(output, i + 1);
            }
            while (!pq.empty() && currsum - pq.top().first >= k)
            {
                output = min(output, i - pq.top().second);
                pq.pop();
            }
            pq.push({currsum, i});
        }

        if (output == INT_MAX)
            return -1;
        else
            return output;
    }
};