/*
leetcode 1034. Coloring A Border
ques:-
Given a 2-dimensional grid of integers, each value in the grid represents the color of the grid square at that location.

Two squares belong to the same connected component if and only if they have the same color and are next to each other in any of the 4 directions.

The border of a connected component is all the squares in the connected component that are either 4-directionally adjacent to a square not in the component, or on the boundary of the grid (the first or last row or column).

Given a square at location (r0, c0) in the grid and a color, color the border of the connected component of that square with the given color, and return the final grid.

Example 1:

Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
Output: [[3, 3], [3, 2]]
Example 2:

Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
Output: [[1, 3, 3], [2, 3, 3]]
Example 3:

Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]
*/

class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int color, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != color)
            return;

        grid[i][j] = -color;

        dfs(grid, i - 1, j, color, n, m);
        dfs(grid, i, j - 1, color, n, m);
        dfs(grid, i + 1, j, color, n, m);
        dfs(grid, i, j + 1, color, n, m);

        if (i > 0 && i < n - 1 && j > 0 && j < m - 1 && abs(grid[i - 1][j]) == color &&
            abs(grid[i + 1][j]) == color && abs(grid[i][j - 1]) == color && abs(grid[i][j + 1]) == color)
            grid[i][j] = color;
    }

    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
    {
        int n = grid.size();
        int m = grid[0].size();

        dfs(grid, r0, c0, grid[r0][c0], n, m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] < 0)
                    grid[i][j] = color;
            }
        }

        return grid;
    }
};