/*
Leetcode 934. Shortest Bridge
ques:-
In a given 2D binary array grid, there are two islands.  (An island is a 4-directionally connected group of 1s not connected to any other 1s.)

Now, we may change 0s to 1s so as to connect the two islands together to form 1 island.

Return the smallest number of 0s that must be flipped.  (It is guaranteed that the answer is at least 1.)


Example 1:

Input: grid = [[0,1],[1,0]]
Output: 1
Example 2:

Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
Output: 2
Example 3:

Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
Output: 1
*/

class Solution
{
public:
    queue<pair<pair<int, int>, int>> q;

    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 || grid[i][j] == 2)
            return;

        grid[i][j] = 2;
        q.push({{i, j}, 0});
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
    }

    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            int j = 0;
            for (; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(grid, i, j, n, m);
                    break;
                }
            }
            if (j != m)
                break;
        }

        while (!q.empty())
        {
            pair<pair<int, int>, int> curr = q.front();
            q.pop();
            int i = curr.first.first;
            int j = curr.first.second;
            int dist = curr.second;

            if (i - 1 >= 0)
            {
                if (grid[i - 1][j] == 1)
                    return dist;
                else if (grid[i - 1][j] == 0)
                {
                    q.push({{i - 1, j}, dist + 1});
                    grid[i - 1][j] = 2;
                }
            }

            if (j - 1 >= 0)
            {
                if (grid[i][j - 1] == 1)
                    return dist;
                else if (grid[i][j - 1] == 0)
                {
                    q.push({{i, j - 1}, dist + 1});
                    grid[i][j - 1] = 2;
                }
            }

            if (i + 1 < n)
            {
                if (grid[i + 1][j] == 1)
                    return dist;
                else if (grid[i + 1][j] == 0)
                {
                    q.push({{i + 1, j}, dist + 1});
                    grid[i + 1][j] = 2;
                }
            }

            if (j + 1 < m)
            {
                if (grid[i][j + 1] == 1)
                    return dist;
                else if (grid[i][j + 1] == 0)
                {
                    q.push({{i, j + 1}, dist + 1});
                    grid[i][j + 1] = 2;
                }
            }
        }
        return -1;
    }
};