/*
Leetcode 200. Number of Islands
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
*/

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j, int rows, int cols)
    {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            return;

        if (grid[i][j] == '1')
        {
            grid[i][j] = '0';
            dfs(grid, i - 1, j, rows, cols);
            dfs(grid, i, j - 1, rows, cols);
            dfs(grid, i + 1, j, rows, cols);
            dfs(grid, i, j + 1, rows, cols);
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j, rows, cols);
                    count++;
                }
            }
        }
        return count;
    }
};
