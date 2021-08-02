/*
Leetcode 827. Making A Large Island
ques:-
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
*/

class Solution
{
public:
    int dfs(vector<vector<int>> &grid, int i, int j, int colour, int m, int n)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1)
            return 0;

        grid[i][j] = colour;
        return dfs(grid, i - 1, j, colour, m, n) + dfs(grid, i, j - 1, colour, m, n) + dfs(grid, i + 1, j, colour, m, n) + dfs(grid, i, j + 1, colour, m, n) + 1;
    }

    int findConverted(vector<vector<int>> &grid, unordered_map<int, int> &areas, int i, int j, int m, int n)
    {
        int count = 1;
        unordered_set<int> visitedareas;
        if (i - 1 >= 0 && visitedareas.find(grid[i - 1][j]) == visitedareas.end())
        {
            count += areas[grid[i - 1][j]];
            visitedareas.insert(grid[i - 1][j]);
        }
        if (j - 1 >= 0 && visitedareas.find(grid[i][j - 1]) == visitedareas.end())
        {
            count += areas[grid[i][j - 1]];
            visitedareas.insert(grid[i][j - 1]);
        }
        if (i + 1 < m && visitedareas.find(grid[i + 1][j]) == visitedareas.end())
        {
            count += areas[grid[i + 1][j]];
            visitedareas.insert(grid[i + 1][j]);
        }
        if (j + 1 < n && visitedareas.find(grid[i][j + 1]) == visitedareas.end())
        {
            count += areas[grid[i][j + 1]];
            visitedareas.insert(grid[i][j + 1]);
        }

        return count;
    }

    int largestIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<int, int> areas;
        int colour = 2;

        int output = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = dfs(grid, i, j, colour, m, n);
                    areas[colour] = area;
                    output = max(output, area);
                    colour++;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int converted = findConverted(grid, areas, i, j, m, n);
                    output = max(output, converted);
                }
            }
        }

        return output;
    }
};