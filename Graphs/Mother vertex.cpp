/*
GeeksforGeeks - Mother Vertex
ques:-
Given a Directed Graph, find a Mother Vertex in the Graph (if present). 
A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.

Example 1:

Input: 

Output: 0
Explanation: According to the given edges, all 
nodes can be reaced from nodes from 0, 1 and 2. 
But, since 0 is minimum among 0,1 and 3, so 0 
is the output.
Example 2:

Input: 

Output: -1
Explanation: According to the given edges, 
no vertices are there from where we can 
reach all vertices. So, output is -1.
*/

class Solution
{
public:
    stack<int> s;

    void dfs(int start, int V, vector<int> adj[], vector<bool> &visited)
    {
        if (start >= V)
            return;

        visited[start] = true;

        for (int i = 0; i < adj[start].size(); i++)
        {
            if (!visited[adj[start][i]])
                dfs(adj[start][i], V, adj, visited);
        }

        s.push(start);
    }

    void dfs2(int start, int V, vector<int> adj[], vector<bool> &visited)
    {
        if (start >= V)
            return;

        visited[start] = true;

        for (int i = 0; i < adj[start].size(); i++)
        {
            if (!visited[adj[start][i]])
                dfs(adj[start][i], V, adj, visited);
        }
    }

    int findMotherVertex(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i, V, adj, visited);
        }

        int scope = s.top();
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }
        dfs2(scope, V, adj, visited);

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
                return -1;
        }
        return scope;
    }
};