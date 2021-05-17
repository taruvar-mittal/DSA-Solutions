/*
GeeksforGeeks - KOSARAJU ALGO - no. of strongly connected components
ques:-
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
 
Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.
*/

class Solution
{
public:
    stack<int> s;

    void dfs(vector<int> adj[], int V, int start, vector<bool> &visited)
    {
        if (start >= V)
            return;

        visited[start] = true;
        for (int i = 0; i < adj[start].size(); i++)
        {
            if (visited[adj[start][i]] == false)
                dfs(adj, V, adj[start][i], visited);
        }

        s.push(start);
    }

    void dfs2(vector<int> adj[], int V, int start, vector<bool> &visited)
    {
        if (start >= V)
            return;

        visited[start] = true;
        for (int i = 0; i < adj[start].size(); i++)
        {
            if (visited[adj[start][i]] == false)
                dfs(adj, V, adj[start][i], visited);
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                dfs(adj, V, i, visited);
        }

        vector<int> reverseGraph[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                reverseGraph[adj[i][j]].push_back(i);
            }
        }

        int count = 0;
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        while (!s.empty())
        {
            if (visited[s.top()])
            {
                s.pop();
                continue;
            }

            dfs2(reverseGraph, V, s.top(), visited);
            s.pop();
            count++;
        }
        return count;
    }
};