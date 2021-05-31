/*
Leetcode 778. Swim in Rising Water
ques:-
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
*/

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int output = INT_MAX;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        grid[0][0] = -1;

        while (!pq.empty())
        {
            vector<int> curr = pq.top();
            pq.pop();
            int weight = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (x == n - 1 && y == n - 1)
                output = min(output, weight);

            if (x - 1 >= 0 && grid[x - 1][y] != -1)
            {
                pq.push({max(weight, grid[x - 1][y]), x - 1, y});
                grid[x - 1][y] = -1;
            }

            if (y - 1 >= 0 && grid[x][y - 1] != -1)
            {
                pq.push({max(weight, grid[x][y - 1]), x, y - 1});
                grid[x][y - 1] = -1;
            }

            if (x + 1 < n && grid[x + 1][y] != -1)
            {
                pq.push({max(weight, grid[x + 1][y]), x + 1, y});
                grid[x + 1][y] = -1;
            }

            if (y + 1 < n && grid[x][y + 1] != -1)
            {
                pq.push({max(weight, grid[x][y + 1]), x, y + 1});
                grid[x][y + 1] = -1;
            }
        }

        return output;
    }
};