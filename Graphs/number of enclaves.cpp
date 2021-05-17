/*
Leetcode 1020. Number of Enclaves
ques:-
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:
Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:
Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
*/

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int rows, int cols)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return;

        if (grid[i][j] == 1)
        {
            grid[i][j] = 0;
            dfs(grid, i - 1, j, rows, cols);
            dfs(grid, i, j - 1, rows, cols);
            dfs(grid, i + 1, j, rows, cols);
            dfs(grid, i, j + 1, rows, cols);
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        // top row
        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 1)
                dfs(grid, 0, i, n, m);
        }

        //bottom row
        for (int i = 0; i < m; i++)
        {
            if (grid[n - 1][i] == 1)
                dfs(grid, n - 1, i, n, m);
        }

        //first column
        for (int i = 1; i < n - 1; i++)
        {
            if (grid[i][0] == 1)
                dfs(grid, i, 0, n, m);
        }

        //last column
        for (int i = 1; i < n - 1; i++)
        {
            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1, n, m);
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    count++;
            }
        }
        return count;
    }
};