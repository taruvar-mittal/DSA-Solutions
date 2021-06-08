/*
Leetcode 1254. Number of Closed Islands
ques:-
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

Example 1:

Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:

Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
*/

class Solution
{
public:
    bool check(int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j > n)
            return false;

        return true;
    }

    bool dfs(vector<vector<int>> &grid, int i, int j, int m, int n)
    {
        bool val = true;
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
            return false;

        grid[i][j] = 2;

        if (check(i - 1, j, m, n) && grid[i - 1][j] == 0)
            val = val & dfs(grid, i - 1, j, m, n);

        if (check(i + 1, j, m, n) && grid[i + 1][j] == 0)
            val = val & dfs(grid, i + 1, j, m, n);

        if (check(i, j - 1, m, n) && grid[i][j - 1] == 0)
            val = val & dfs(grid, i, j - 1, m, n);

        if (check(i, j + 1, m, n) && grid[i][j + 1] == 0)
            val = val & dfs(grid, i, j + 1, m, n);

        return val;
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    if (dfs(grid, i, j, m, n))
                        count++;
                }
            }
        }

        return count;
    }
};