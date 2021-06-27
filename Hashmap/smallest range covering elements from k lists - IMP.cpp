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
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
        {
            for (auto j : nums[i])
            {
                v.push_back({j, i});
            }
        }
        sort(v.begin(), v.end());
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[i] = 0;
        }
        int count = 0;

        int mini = INT_MAX;
        int maxi = INT_MIN;
        int range = INT_MAX;

        int i = 0;
        int j = 0;

        while (j < v.size())
        {
            pair<int, int> curr = v[j];
            mp[curr.second]++;
            if (mp[curr.second] == 1)
                count++;
            while (count == mp.size())
            {
                if (v[j].first - v[i].first < range || (v[j].first - v[i].first == range && v[i].first < mini))
                {
                    range = v[j].first - v[i].first;
                    maxi = v[j].first;
                    mini = v[i].first;
                }
                mp[v[i].second]--;
                if (mp[v[i].second] == 0)
                    count--;
                i++;
            }
            j++;
        }

        return {mini, maxi};
    }
};