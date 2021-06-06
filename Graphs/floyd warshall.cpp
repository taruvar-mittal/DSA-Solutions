/*
Geeks for Geeks - FLOYD WARSHALL
All pairs shprtest paths 

ques:-
The problem is to find shortest distances between every pair of vertices in a given edge weighted directed Graph. The Graph is represented as adjancency matrix, and the matrix denotes the weight of the edegs (if it exists) else -1. Do it in-place.
 
Example 1:

Input: matrix = {{0,25},{-1,0}}
Output: {{0,25},{-1,0}}
Explanation: The shortest distance between
every pair is already given(if it exists).
Example 2:

Input: matrix = {{0,1,43},{1,0,6},{-1,-1,0}}
Output: {{0,1,7},{1,0,6},{-1,-1,0}}
Explanation: We can reach 3 from 1 as 1->2->3
and the cost will be 1+6=7 which is less than 
43.
*/

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &dp)
    {
        int n = dp.size();

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j || i == k || j == k)
                        continue;
                    else if (dp[i][k] == -1 || dp[k][j] == -1)
                        continue;
                    else
                    {
                        if (dp[i][j] != -1)
                            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                        else
                            dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
    }
};