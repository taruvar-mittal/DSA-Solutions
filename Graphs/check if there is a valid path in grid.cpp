/*
Leetcode 1391. Check if There is a Valid Path in a Grid
ques:-
Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.


You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.

Return true if there is a valid path in the grid or false otherwise.

 

Example 1:


Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
Example 2:


Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)
Example 3:

Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).
Example 4:

Input: grid = [[1,1,1,1,1,1,3]]
Output: true
Example 5:

Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
Output: true
*/

class Solution
{
public:
    bool check(int i, int j, int m, int n)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        return true;
    }

    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int i, int j, int m, int n)
    {
        if (visited[i][j])
            return;
        visited[i][j] = true;

        int up, down, left, right = 0;

        int p = grid[i][j];

        if (p == 1)
            left = right = 1;
        else if (p == 2)
            up = down = 1;
        else if (p == 3)
            left = down = 1;
        else if (p == 4)
            down = up = 1;
        else if (p == 5)
            left = up = 1;
        else if (p == 6)
            up = right = 1;

        if (up == 1)
        {
            int x = i - 1;
            int y = j;
            if (check(x, y, m, n) && (grid[x][y] == 2 || grid[x][y] == 3 || grid[x][y] == 4))
                dfs(grid, visited, x, y, m, n);
        }

        if (down == 1)
        {
            int x = i + 1;
            int y = j;
            if (check(x, y, m, n) && (grid[x][y] == 2 || grid[x][y] == 5 || grid[x][y] == 6))
                dfs(grid, visited, x, y, m, n);
        }

        if (left == 1)
        {
            int x = i;
            int y = j - 1;
            if (check(x, y, m, n) && (grid[x][y] == 1 || grid[x][y] == 3 || grid[x][y] == 5))
                dfs(grid, visited, x, y, m, n);
        }

        if (right == 1)
        {
            int x = i;
            int y = j + 1;
            if (check(x, y, m, n) && (grid[x][y] == 1 || grid[x][y] == 4 || grid[x][y] == 6))
                dfs(grid, visited, x, y, m, n);
        }
    }

    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        dfs(grid, visited, 0, 0, m, n);

        return visited[m - 1][n - 1];
    }
};