/*
Leetcode 407. Trapping Rain Water II
ques:-
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

Example 1:


Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small pounds 1 and 3 units trapped.
The total volume of water trapped is 4.
Example 2:


Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
*/

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int m = heightMap.size();
        int n = heightMap[0].size();

        if (m <= 2 || n <= 2)
            return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // top and bottom row
        for (int i = 0; i < n; i++)
        {
            if (!visited[0][i])
            {
                visited[0][i] = true;
                pq.push({heightMap[0][i], {0, i}});
            }

            if (!visited[m - 1][i])
            {
                visited[m - 1][i] = true;
                pq.push({heightMap[m - 1][i], {m - 1, i}});
            }
        }

        // left and right col
        for (int i = 0; i < m; i++)
        {
            if (!visited[i][0])
            {
                visited[i][0] = true;
                pq.push({heightMap[i][0], {i, 0}});
            }

            if (!visited[i][n - 1])
            {
                visited[i][n - 1] = true;
                pq.push({heightMap[i][n - 1], {i, n - 1}});
            }
        }

        long long int output = 0;

        while (!pq.empty())
        {
            pair<int, pair<int, int>> curr = pq.top();
            pq.pop();

            int currheight = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            // cout<<currheight<<x<<y<<endl;

            if (x - 1 >= 0 && !visited[x - 1][y])
            {
                visited[x - 1][y] = true;
                if (heightMap[x - 1][y] < currheight)
                {
                    output += currheight - heightMap[x - 1][y];
                    heightMap[x - 1][y] = currheight;
                }
                pq.push({heightMap[x - 1][y], {x - 1, y}});
            }

            if (x + 1 < m && !visited[x + 1][y])
            {
                visited[x + 1][y] = true;
                if (heightMap[x + 1][y] < currheight)
                {
                    output += currheight - heightMap[x + 1][y];
                    heightMap[x + 1][y] = currheight;
                }
                pq.push({heightMap[x + 1][y], {x + 1, y}});
            }

            if (y - 1 >= 0 && !visited[x][y - 1])
            {
                visited[x][y - 1] = true;
                if (heightMap[x][y - 1] < currheight)
                {
                    output += currheight - heightMap[x][y - 1];
                    heightMap[x][y - 1] = currheight;
                }
                pq.push({heightMap[x][y - 1], {x, y - 1}});
            }

            if (y + 1 < n && !visited[x][y + 1])
            {
                visited[x][y + 1] = true;
                if (heightMap[x][y + 1] < currheight)
                {
                    output += currheight - heightMap[x][y + 1];
                    heightMap[x][y + 1] = currheight;
                }
                pq.push({heightMap[x][y + 1], {x, y + 1}});
            }
        }
        return output;
    }
};