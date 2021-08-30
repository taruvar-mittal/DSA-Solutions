/*
Lintcode 920 · Meeting Rooms
ques:-
Description
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

(0,8),(8,10) is not conflict at 8

Example
Example1

Input: intervals = [(0,30),(5,10),(15,20)]
Output: false
Explanation: 
(0,30), (5,10) and (0,30),(15,20) will conflict
Example2

Input: intervals = [(5,8),(9,15)]
Output: true
Explanation: 
Two times will not conflict 
*/

class Solution
{
public:
    static bool comp(Interval i, Interval j)
    {
        return i.start <= j.start;
    }
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        sort(intervals.begin(), intervals.end(), comp);

        // for(auto i:intervals){
        //     cout<<i.start<<" "<<i.end<<endl;
        // }

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i].start < intervals[i - 1].end)
                return false;
        }

        return true;
    }
};