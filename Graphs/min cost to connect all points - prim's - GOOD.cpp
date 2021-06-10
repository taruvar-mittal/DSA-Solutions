/*
Leetcode 1584. Min Cost to Connect All Points
ques:-
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 

Example 1:



Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
Example 3:

Input: points = [[0,0],[1,1],[1,0],[-1,1]]
Output: 4
Example 4:

Input: points = [[-1000000,-1000000],[1000000,1000000]]
Output: 4000000
Example 5:

Input: points = [[0,0]]
Output: 0
*/

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<vector<pair<int, int>>> distances(n, vector<pair<int, int>>());

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                distances[i].push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), j});
                distances[j].push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);

        pq.push({0, 0});

        int output = 0;

        while (!pq.empty())
        {
            pair<int, int> curr = pq.top();
            pq.pop();

            if (visited[curr.second])
                continue;

            output += curr.first;
            int v = curr.second;
            visited[v] = true;

            for (int i = 0; i < distances[v].size(); i++)
            {
                if (!visited[distances[v][i].second])
                    pq.push({distances[v][i].first, distances[v][i].second});
            }
        }

        return output;
    }
};