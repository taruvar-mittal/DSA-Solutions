/*
Leetcode 980. Unique Paths III
ques:-
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

Example 1:

Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
Output: 2
Explanation: We have the following two paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
Example 2:

Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
Output: 4
Explanation: We have the following four paths: 
1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
Example 3:

Input: [[0,1],[2,0]]
Output: 0
Explanation: 
There is no path that walks over every empty square exactly once.
Note that the starting and ending square can be anywhere in the grid.
*/

class Solution
{
public:
    int ans = 0;
    int totalzeroes = 0;

    void dfs(vector<vector<int>> &grid, int x, int y, int n, int m)
    {
        if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == -1)
            return;

        if (grid[x][y] == 2)
        {
            if (totalzeroes == 0)
                ans++;
            return;
        }

        grid[x][y] = -1;
        totalzeroes--;

        dfs(grid, x - 1, y, n, m);
        dfs(grid, x, y - 1, n, m);
        dfs(grid, x + 1, y, n, m);
        dfs(grid, x, y + 1, n, m);

        totalzeroes++;
        grid[x][y] = 0;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {

        int x = -1, y = -1;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                    totalzeroes++;
                else if (grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        }

        grid[x][y] = -1;
        dfs(grid, x - 1, y, n, m);
        dfs(grid, x, y - 1, n, m);
        dfs(grid, x + 1, y, n, m);
        dfs(grid, x, y + 1, n, m);

        return ans;
    }
};