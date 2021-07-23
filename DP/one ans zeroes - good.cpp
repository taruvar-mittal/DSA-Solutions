/*
Leetcode 474. Ones and Zeroes
ques:-
You are given an array of binary strings strs and two integers m and n.

Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

A set x is a subset of a set y if all elements of x are also elements of y.

Example 1:

Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
Output: 4
Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
{"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
Example 2:

Input: strs = ["10","0","1"], m = 1, n = 1
Output: 2
Explanation: The largest subset is {"0", "1"}, so the answer is 2.
*/

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<pair<int, int>> count;
        for (auto s : strs)
        {
            int zerocount = 0, onecount = 0;
            for (auto c : s)
            {
                if (c == '0')
                    zerocount++;
                else
                    onecount++;
            }
            count.push_back({zerocount, onecount});
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto p : count)
        {
            for (int i = m; i >= p.first; i--)
            {
                for (int j = n; j >= p.second; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - p.first][j - p.second] + 1);
                }
            }
        }
        return dp[m][n];
    }
};