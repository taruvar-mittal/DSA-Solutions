/*
Leetcode 1514. Path with Maximum Probability
ques:-
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.


Example 1:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:

Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:

Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
*/

class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
    {
        vector<vector<pair<int, double>>> graph(n, vector<pair<int, double>>());

        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> visited(n, -1);
        priority_queue<pair<double, int>> pq;

        pq.push({(double)1.0, start});

        while (!pq.empty())
        {

            pair<double, int> curr = pq.top();
            pq.pop();

            double u = curr.first;
            int v = curr.second;

            if (v == end)
                return u;

            visited[v] = u;

            for (int i = 0; i < graph[v].size(); i++)
            {
                if (visited[graph[v][i].first] == -1)
                {
                    pq.push({u * graph[v][i].second, graph[v][i].first});
                }
            }
        }

        return 0;
    }
};