/*
Leetcode 1162. As Far from Land as Possible
ques:-
Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

Example 1:

Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
Output: 2
Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.
Example 2:

Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
Output: 4
Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
*/

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> output(n, vector<int>(m, -1));
        queue<pair<pair<int, int>, int>> pendingNodes;

        bool zeropresent = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    output[i][j] = 0;
                    pendingNodes.push({{i, j}, 0});
                }
                else if (grid[i][j] == 0)
                    zeropresent = true;
            }
        }

        if (!zeropresent)
            return -1;
        int ans = -1;

        while (!pendingNodes.empty())
        {
            pair<pair<int, int>, int> curr = pendingNodes.front();
            pendingNodes.pop();
            int i = curr.first.first;
            int j = curr.first.second;
            int dist = curr.second;
            ans = max(dist, ans);

            if (i - 1 >= 0 && output[i - 1][j] == -1)
            {
                output[i - 1][j] = dist + 1;
                pendingNodes.push({{i - 1, j}, dist + 1});
            }
            if (j - 1 >= 0 && output[i][j - 1] == -1)
            {
                output[i][j - 1] = dist + 1;
                pendingNodes.push({{i, j - 1}, dist + 1});
            }

            if (i + 1 < n && output[i + 1][j] == -1)
            {
                output[i + 1][j] = dist + 1;
                pendingNodes.push({{i + 1, j}, dist + 1});
            }
            if (j + 1 < m && output[i][j + 1] == -1)
            {
                output[i][j + 1] = dist + 1;
                pendingNodes.push({{i, j + 1}, dist + 1});
            }
        }
        return ans;
    }
};