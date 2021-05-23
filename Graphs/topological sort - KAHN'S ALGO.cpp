/*
GeeksforGeeks - topological sort using KAHN's ALGORITHM
*/

class Solution
{
public:
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> output;
        vector<int> indegree(V, 0);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                indegree[adj[i][j]]++;
            }
        }

        queue<int> pendingNodes;
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
                pendingNodes.push(i);
        }

        while (!pendingNodes.empty())
        {
            int curr = pendingNodes.front();
            pendingNodes.pop();
            output.push_back(curr);
            for (int i = 0; i < adj[curr].size(); i++)
            {
                indegree[adj[curr][i]]--;
                if (indegree[adj[curr][i]] == 0)
                    pendingNodes.push(adj[curr][i]);
            }
        }

        return output;
    }
};