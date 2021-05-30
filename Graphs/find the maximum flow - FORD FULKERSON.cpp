/*
GeeksforGeeks - find the maximum flow
Given a graph with N vertices numbered 1 to N and M edges, The task is to find the max flow from vertex 1 to vertex N.

Example 1:

Input:
N = 5, M =  4
Edges[]= { {1, 2, 1} , {3, 2, 2}, {4, 2, 3}, {2, 5, 5} }
Output:
1 
Explanation: 
1 - 2 - 3
   / \
  4   5 
1 unit can flow from 1 -> 2 - >5 
 

Example 2:

Input:
N = 4 , M = 4
Edges[] = { {1, 2, 8}, {1, 3, 10}, {4, 2, 2}, {3, 4, 3} }
Output:
5 
Explanation:
  1 - 2 
  |   |
  3 - 4
3 unit can flow from 1 -> 3 -> 4
2 unit can flow from 1 -> 2 -> 4
Total max flow from 1 to N = 3+2=5
Your Task: 
You don't need to read input or print anything. Your task is to complete the function solve() which takes the N (the number of vertices) ,M (the number of Edges) and the array Edges[] (Where Edges[i] denoting an undirected edge between Edges[i][0] and Edges[i][1] with a flow capacity of Edges[i][2] ), and returns the integer denoting the maximum flow from 1 to N.

Expected Time Complexity: O( max_flow* M)
Expected Auxiliary Space: O(N+M)

Where max_flow is the maximum flow from 1 to N
*/

class Solution
{
public:
    void bfs(vector<vector<int>> &graph, int src, int sink, vector<int> &parent, int N)
    {
        vector<bool> visited(N, false);
        queue<int> pendingNodes;
        pendingNodes.push(src);
        visited[src] = true;

        while (!pendingNodes.empty())
        {
            int u = pendingNodes.front();
            pendingNodes.pop();
            for (int v = 0; v < N; v++)
            {
                if (visited[v] == false && graph[u][v] > 0)
                {
                    pendingNodes.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
    }

    int solve(int N, int M, vector<vector<int>> Edges)
    {
        vector<vector<int>> graph(N, vector<int>(N, 0));

        for (int i = 0; i < M; i++)
        {
            int u = Edges[i][0] - 1;
            int v = Edges[i][1] - 1;
            int w = Edges[i][2];
            graph[u][v] += w;
            graph[v][u] += w;
        }

        int ans = 0;

        while (true)
        {
            vector<int> parent(N, -1);
            bfs(graph, 0, N - 1, parent, N);

            if (parent[N - 1] == -1)
                break;

            int minweight = INT_MAX;
            for (int v = N - 1; v != 0; v = parent[v])
            {
                int u = parent[v];
                minweight = min(minweight, graph[u][v]);
            }

            ans += minweight;

            for (int v = N - 1; v != 0; v = parent[v])
            {
                int u = parent[v];
                graph[u][v] -= minweight;
                graph[v][u] += minweight;
            }
        }

        return ans;
    }
};