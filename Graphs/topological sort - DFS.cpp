/*
GeeksforGeeks topological sort using DFS
ques:-
Given a Directed Graph with V vertices and E edges, Find any Topological Sorting of that Graph.
*/

class Solution
{
public:
    vector<int> output;

    void dfs(vector<int> adj[], vector<bool> &visited, int vertex, int V)
    {
        visited[vertex] = true;
        for (int i = 0; i < adj[vertex].size(); i++)
        {
            if (!visited[adj[vertex][i]])
                dfs(adj, visited, adj[vertex][i], V);
        }
        output.push_back(vertex);
    }

    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(adj, visited, i, V);
        }

        reverse(output.begin(), output.end());
        return output;
    }
};