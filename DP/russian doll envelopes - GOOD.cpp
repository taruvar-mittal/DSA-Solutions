/*
Leetcode 354. Russian Doll Envelopes
ques:-
You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
*/

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), comp);

        vector<int> heights;
        for (auto v : envelopes)
        {
            heights.push_back(v[1]);
        }

        int ans = 0;
        int n = heights.size();
        vector<int> lis(n, 0);

        for (int i = 0; i < n; i++)
        {
            int low = 0;
            int high = ans;
            while (low < high)
            {
                int mid = low + (high - low) / 2;
                if (heights[i] > lis[mid])
                    low = mid + 1;
                else
                    high = mid;
            }
            lis[low] = heights[i];
            if (low == ans)
                ans++;
        }

        return ans;
    }
};