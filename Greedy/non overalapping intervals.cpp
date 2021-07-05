/*
Leetcode 435. Non-overlapping Intervals
ques:-
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int count = 0;

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] < end)
            {
                count++;
                if (intervals[i][1] < end)
                {
                    start = intervals[i][0];
                    end = intervals[i][1];
                }
            }
            else
            {
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        return count;
    }
};