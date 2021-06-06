/*
Leetcode 803. Bricks Falling When Hit
Ques:-
You are given an m x n binary grid, where each 1 represents a brick and 0 represents an empty space. A brick is stable if:

It is directly connected to the top of the grid, or
At least one other brick in its four adjacent cells is stable.
You are also given an array hits, which is a sequence of erasures we want to apply. Each time we want to erase the brick at the location hits[i] = (rowi, coli). The brick on that location (if it exists) will disappear. Some other bricks may no longer be stable because of that erasure and will fall. Once a brick falls, it is immediately erased from the grid (i.e., it does not land on other stable bricks).

Return an array result, where each result[i] is the number of bricks that will fall after the ith erasure is applied.

Note that an erasure may refer to a location with no brick, and if it does, no bricks drop.

 

Example 1:

Input: grid = [[1,0,0,0],[1,1,1,0]], hits = [[1,0]]
Output: [2]
Explanation: Starting with the grid:
[[1,0,0,0],
 [1,1,1,0]]
We erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,1,1,0]]
The two underlined bricks are no longer stable as they are no longer connected to the top nor adjacent to another stable brick, so they will fall. The resulting grid is:
[[1,0,0,0],
 [0,0,0,0]]
Hence the result is [2].
Example 2:

Input: grid = [[1,0,0,0],[1,1,0,0]], hits = [[1,1],[1,0]]
Output: [0,0]
Explanation: Starting with the grid:
[[1,0,0,0],
 [1,1,0,0]]
We erase the underlined brick at (1,1), resulting in the grid:
[[1,0,0,0],
 [1,0,0,0]]
All remaining bricks are still stable, so no bricks fall. The grid remains the same:
[[1,0,0,0],
 [1,0,0,0]]
Next, we erase the underlined brick at (1,0), resulting in the grid:
[[1,0,0,0],
 [0,0,0,0]]
Once again, all remaining bricks are still stable, so no bricks fall.
Hence the result is [0,0].
*/

class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        if (x == parent[x])
            return x;
        int temp = find(parent, parent[x]);
        parent[x] = temp;
        return temp;
    }

    void merge(vector<int> &parent, vector<int> &size, int x, int y)
    {
        int pox = find(parent, x);
        int poy = find(parent, y);

        if (pox == poy)
            return;

        parent[pox] = poy;
        size[poy] += size[pox];
    }

    void mergeAround(vector<vector<int>> &grid, vector<int> &parent, vector<int> &size, int i, int j, int m, int n)
    {
        int cellnum = i * n + j + 1;

        if (i - 1 >= 0)
        {
            if (grid[i - 1][j] == 1)
                merge(parent, size, cellnum, (i - 1) * n + j + 1);
        }

        if (j - 1 >= 0)
        {
            if (grid[i][j - 1] == 1)
                merge(parent, size, cellnum, i * n + (j - 1) + 1);
        }

        if (i + 1 < m)
        {
            if (grid[i + 1][j] == 1)
                merge(parent, size, cellnum, (i + 1) * n + j + 1);
        }

        if (j + 1 < n)
        {
            if (grid[i][j + 1] == 1)
                merge(parent, size, cellnum, i * n + (j + 1) + 1);
        }

        if (i == 0)
            merge(parent, size, 0, cellnum);
    }

    vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> parent(m * n + 1);
        for (int i = 0; i < m * n + 1; i++)
        {
            parent[i] = i;
        }
        vector<int> size(m * n + 1, 1);

        for (auto hit : hits)
        {
            if (grid[hit[0]][hit[1]] == 1)
                grid[hit[0]][hit[1]] = 2;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    mergeAround(grid, parent, size, i, j, m, n);
            }
        }

        vector<int> output(hits.size());
        int bricksleft = size[find(parent, 0)];

        for (int i = hits.size() - 1; i >= 0; i--)
        {
            int x = hits[i][0];
            int y = hits[i][1];
            if (grid[x][y] == 2)
            {
                grid[x][y] = 1;
                mergeAround(grid, parent, size, x, y, m, n);
                int currbricksleft = size[find(parent, 0)];
                output[i] = max(currbricksleft - bricksleft - 1, 0);
                bricksleft = currbricksleft;
            }
        }
        return output;
    }
};