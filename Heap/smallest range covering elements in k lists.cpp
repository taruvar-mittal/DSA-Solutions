/*
Leetcode 632. Smallest Range Covering Elements from K Lists
ques:-
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
Example 3:

Input: nums = [[10,10],[11,11]]
Output: [10,11]
Example 4:

Input: nums = [[10],[11]]
Output: [10,11]
Example 5:

Input: nums = [[1],[2],[3],[4],[5],[6],[7]]
Output: [1,7]
*/

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int k = nums.size();

        int maxi = INT_MIN;
        int start = 0;
        int end = INT_MAX;

        for (int i = 0; i < k; i++)
        {
            pq.push({nums[i][0], i, 0});
            maxi = max(maxi, nums[i][0]);
        }

        while (pq.size() == k)
        {
            vector<int> curr = pq.top();
            pq.pop();

            if (end - start > maxi - curr[0])
            {
                start = curr[0];
                end = maxi;
            }

            if (curr[2] + 1 < nums[curr[1]].size())
            {
                pq.push({nums[curr[1]][curr[2] + 1], curr[1], curr[2] + 1});
                maxi = max(maxi, nums[curr[1]][curr[2] + 1]);
            }
        }

        return {start, end};
    }
};