/*
Lintcode 908 · Line Reflection
ques:-
Description
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example1

Input: [[1,1],[-1,1]]
Output: true
Example2

Input: [[1,1],[-1,-1]]
Output: false
*/

class Solution
{
public:
    bool isReflected(vector<vector<int>> &points)
    {
        int minx = INT_MAX;
        int maxx = INT_MIN;
        unordered_map<int, unordered_set<int>> mp;
        for (auto v : points)
        {
            minx = min(minx, v[0]);
            maxx = max(maxx, v[0]);
            mp[v[0]].insert(v[1]);
        }

        int mirror = (minx + maxx);
        for (auto v : points)
        {
            int x1 = v[0];
            int x2 = mirror - x1;
            if (mp.find(x1) == mp.end() || mp[x2].find(v[1]) == mp[x2].end())
                return false;
        }
        return true;
    }
};