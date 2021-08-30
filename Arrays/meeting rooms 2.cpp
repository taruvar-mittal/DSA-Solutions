/*
Lintcode 919 · Meeting Rooms II
ques:-
Description
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example
Example1

Input: intervals = [(0,30),(5,10),(15,20)]
Output: 2
Explanation:
We need two meeting rooms
room1: (0,30)
room2: (5,10),(15,20)
Example2

Input: intervals = [(2,7)]
Output: 1
Explanation: 
Only need one meeting room
*/

class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        vector<pair<int, int>> v;
        for (auto i : intervals)
        {
            v.push_back({i.start, 1});
            v.push_back({i.end, -1});
        }

        sort(v.begin(), v.end());
        int rooms = 0;
        int ans = 0;

        for (auto i : v)
        {
            rooms += i.second;
            ans = max(ans, rooms);
        }

        return ans;
    }
};