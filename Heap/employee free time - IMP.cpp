/*
Lintcode 850 · Employee Free Time
ques:-
Description
We are given a list schedule of employees, which represents the working time for each employee.

Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.

Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.

The Intervals is an 1d-array. Each two numbers shows an interval. For example, [1,2,8,10] represents that the employee works in [1,2] and [8,10].

Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

1.schedule and schedule[i] are lists with lengths in range [1, 100].
2.0 <= schedule[i].start < schedule[i].end <= 10^8.

Example
Example 1:

Input：schedule = [[1,2,5,6],[1,3],[4,10]]
Output：[(3,4)]
Explanation:
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [3, 4], [10, inf].
We discard any intervals that contain inf as they aren't finite.
Example 2:

Input：schedule = [[1,3,6,7],[2,4],[2,5,9,12]]
Output：[(5,6),(7,9)]
Explanation：
There are a total of three employees, and all common
free time intervals would be [-inf, 1], [5, 6], [7, 9],[12,inf].
We discard any intervals that contain inf as they aren't finite.
*/

class Solution
{
public:
    vector<Interval> employeeFreeTime(vector<vector<int>> &schedule)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for (int i = 0; i < schedule.size(); i++)
        {
            for (int j = 0; j < schedule[i].size(); j += 2)
            {
                pq.push({schedule[i][j], schedule[i][j + 1]});
            }
        }
        vector<Interval> output;
        vector<int> prev = pq.top();
        pq.pop();

        while (!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            // cout<<curr[0]<<curr[1]<<curr[2]<<curr[3]<<endl;
            if (prev[1] < curr[0])
            {
                Interval i(prev[1], curr[0]);
                output.push_back(i);
            }
            if (prev[1] < curr[1])
                prev = curr;
        }
        return output;
    }
};