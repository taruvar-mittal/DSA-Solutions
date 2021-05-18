/*
Leetcode 1557. Minimum Number of Vertices to Reach All Nodes
ques:-
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.

Example 1:

Input: n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
Output: [0,3]
Explanation: It's not possible to reach all the nodes from a single vertex. From 0 we can reach [0,1,2,5]. From 3 we can reach [3,4,2,5]. So we output [0,3].
Example 2:

Input: n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
Output: [0,2,3]
Explanation: Notice that vertices 0, 3 and 2 are not reachable from any other node, so we must include them. Also any of these vertices can reach nodes 1 and 4.
*/

class Solution
{
public:
    stack<int> s;

    void dfs(vector<vector<int>> &graph, vector<bool> &visited, int vertex, int n)
    {
        if (vertex >= n)
            return;

        visited[vertex] = true;
        for (int i = 0; i < graph[vertex].size(); i++)
        {
            if (!visited[graph[vertex][i]])
                dfs(graph, visited, graph[vertex][i], n);
        }
        s.push(vertex);
    }

    void dfs2(vector<vector<int>> &graph, vector<bool> &visited, int vertex, int n)
    {
        if (vertex >= n)
            return;

        visited[vertex] = true;
        for (int i = 0; i < graph[vertex].size(); i++)
        {
            if (!visited[graph[vertex][i]])
                dfs(graph, visited, graph[vertex][i], n);
        }
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n, vector<int>());
        for (int i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs(graph, visited, i, n);
        }

        vector<int> output;
        for (int i = 0; i < n; i++)
            visited[i] = false;

        while (!s.empty())
        {
            if (!visited[s.top()])
            {
                output.push_back(s.top());
                dfs2(graph, visited, s.top(), n);
            }
            s.pop();
        }
        return output;
    }
};