/*
Leetcode 743. Network Delay Time
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for (int i = 0; i < times.size(); i++)
        {
            graph[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }
        k--;
        vector<int> cost(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({k, 0});
        cost[k] = 0;

        while (!pq.empty())
        {
            pair<int, int> curr = pq.top();
            pq.pop();
            for (int i = 0; i < graph[curr.first].size(); i++)
            {
                int newcost = curr.second + graph[curr.first][i].second;
                int node = graph[curr.first][i].first;
                if (cost[node] > newcost)
                {
                    cost[node] = newcost;
                    pq.push({node, newcost});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (cost[i] == INT_MAX)
                return -1;
            ans = max(ans, cost[i]);
        }
        return ans;
    }
};