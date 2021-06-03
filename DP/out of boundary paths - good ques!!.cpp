/*
Leetcode 576. Out of Boundary Paths
ques:-
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent four cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

Example 1:

Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
Example 2:

Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
 
Constraints:
1 <= m, n <= 50
0 <= maxMove <= 50
0 <= startRow <= m
0 <= startColumn <= n
*/

class Solution
{
public:
    long long output = 0;
    int dp[51][51][51];

    int dfs(int i, int j, int m, int n, int moves)
    {
        if (moves < 0)
            return 0;

        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return 1;
        }

        if (dp[i][j][moves] != -1)
            return dp[i][j][moves];

        long long temp = 0;

        temp += dfs(i - 1, j, m, n, moves - 1) % 1000000007;
        temp += dfs(i, j - 1, m, n, moves - 1) % 1000000007;
        temp += dfs(i + 1, j, m, n, moves - 1) % 1000000007;
        temp += dfs(i, j + 1, m, n, moves - 1) % 1000000007;

        dp[i][j][moves] = temp % 1000000007;
        return dp[i][j][moves];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {

        memset(dp, -1, sizeof dp);

        output = dfs(startRow, startColumn, m, n, maxMove);
        return output % 1000000007;
    }
};