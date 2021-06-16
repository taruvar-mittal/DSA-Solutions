/*
Leetcode 1129. Shortest Path with Alternating Colors
ques:-
Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph, each edge is either red or blue, and there could be self-edges or parallel edges.

Each [i, j] in red_edges denotes a red directed edge from node i to node j.  Similarly, each [i, j] in blue_edges denotes a blue directed edge from node i to node j.

Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to node X such that the edge colors alternate along the path (or -1 if such a path doesn't exist).

 

Example 1:

Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
Output: [0,1,-1]
Example 2:

Input: n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
Output: [0,1,-1]
Example 3:

Input: n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
Output: [0,-1,-1]
Example 4:

Input: n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
Output: [0,1,2]
Example 5:

Input: n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
Output: [0,1,1]
*/

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &red_edges, vector<vector<int>> &blue_edges)
    {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());

        for (auto v : red_edges)
        {
            graph[v[0]].push_back({v[1], 1});
        }
        for (auto v : blue_edges)
        {
            graph[v[0]].push_back({v[1], 2});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        vector<int> output(n, -1);

        while (!pq.empty())
        {
            int size = pq.size();
            while (size--)
            {
                pair<int, pair<int, int>> curr = pq.top();
                pq.pop();

                int dist = curr.first;
                int node = curr.second.first;
                int color = curr.second.second;

                if (output[node] == -1)
                    output[node] = dist;
                else
                    output[node] = min(output[node], dist);

                for (int i = 0; i < graph[node].size(); i++)
                {
                    if (graph[node][i].first != -1)
                    {
                        if (graph[node][i].second != color)
                        {
                            pq.push({dist + 1, {graph[node][i].first, graph[node][i].second}});

                            graph[node][i].first = -1; // marking edge as visited
                        }
                    }
                }
            }
        }

        return output;
    }
};