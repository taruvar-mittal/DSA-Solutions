/*
Leetcode 417. Pacific Atlantic Water Flow
ques:-
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.


Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Example 2:

Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]
*/

class Solution
{
public:
    void dfs(vector<vector<bool>> &grid, vector<vector<int>> &heights, int row, int col, int m, int n)
    {

        if (grid[row][col])
            return;

        grid[row][col] = true;

        if (row - 1 >= 0 && heights[row - 1][col] >= heights[row][col])
            dfs(grid, heights, row - 1, col, m, n);

        if (col - 1 >= 0 && heights[row][col - 1] >= heights[row][col])
            dfs(grid, heights, row, col - 1, m, n);

        if (row + 1 < m && heights[row + 1][col] >= heights[row][col])
            dfs(grid, heights, row + 1, col, m, n);

        if (col + 1 < n && heights[row][col + 1] >= heights[row][col])
            dfs(grid, heights, row, col + 1, m, n);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            dfs(pacific, heights, i, 0, m, n);
            dfs(atlantic, heights, i, n - 1, m, n);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(pacific, heights, 0, i, m, n);
            dfs(atlantic, heights, m - 1, i, m, n);
        }

        vector<vector<int>> output;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                    output.push_back({i, j});
            }
        }
        return output;
    }
};