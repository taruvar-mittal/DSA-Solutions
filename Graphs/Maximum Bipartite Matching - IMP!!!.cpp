/*
GeeksforGeeks - Maximum Bipartite Matching 
ques:-
There are M job applicants and N jobs.  Each applicant has a subset of jobs that he/she is interseted in. Each job opening can only accept one applicant and a job applicant can be appointed for only one job. Given a matrix G where G(i,j) denotes ith applicant is interested in jth job. Find an assignment of jobs to applicant in such that as many applicants as possible get jobs.
 

Example 1:

Input: G = {{1,1,0,1,1},{0,1,0,0,1},
{1,1,0,1,1}}
Output: 3
Explanation: There is one of the possible
assignment-
First applicant gets the 1st job.
Second applicant gets the 2nd job.
Third applicant gets the 3rd job.
Example 2:

Input: G = {{1,1},{0,1},{0,1},{0,1},
{0,1},{1,0}}
Output: 2
Explanation: There is one of the possible
assignment-
First applicant gets the 1st job.
Second applicant gets the 2nd job.
 

Your Task:
You don't need to read to print anything. Your task is to complete the function maximumMatch() which takes matrix G as input parameter and returns the maximum number of applicants who can get the job.
 

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N)
 

Constraints:
1 ≤ N, M ≤ 100
*/

class Solution
{
public:
    void bfs(vector<vector<int>> &graph, int src, int sink, vector<int> &parent)
    {
        vector<bool> visited(sink + 1, false);
        queue<int> pendingNodes;
        pendingNodes.push(src);
        visited[src] = true;

        while (!pendingNodes.empty())
        {
            int u = pendingNodes.front();
            pendingNodes.pop();
            for (int i = 0; i < sink + 1; i++)
            {
                if (!visited[i] && graph[u][i] > 0)
                {
                    pendingNodes.push(i);
                    visited[i] = true;
                    parent[i] = u;
                }
            }
        }
    }

    int maximumMatch(vector<vector<int>> &G)
    {
        int m = G.size();
        int n = G[0].size();

        vector<vector<int>> graph(m + n + 2, vector<int>(m + n + 2, 0));

        for (int i = 1; i <= m; i++)
        {
            graph[0][i] = 1;
        }

        for (int i = 0; i < G.size(); i++)
        {
            for (int j = 0; j < G[0].size(); j++)
            {
                if (G[i][j] == 1)
                    graph[i + 1][m + j + 1] = 1;
            }
        }

        for (int x = m + 1; x < m + n + 1; x++)
        {
            graph[x][m + n + 1] = 1;
        }

        int ans = 0;

        int src = 0;
        int sink = m + n + 2 - 1;

        while (true)
        {
            vector<int> parent(sink + 1, -1);
            bfs(graph, src, sink, parent);
            if (parent[sink] == -1)
                break;

            int minweight = INT_MAX;

            for (int v = sink; v != src; v = parent[v])
            {
                int u = parent[v];
                minweight = min(minweight, graph[u][v]);
            }

            ans += minweight;

            for (int v = sink; v != src; v = parent[v])
            {
                int u = parent[v];
                graph[u][v] -= minweight;
                graph[v][u] += minweight;
            }
        }
        return ans;
    }
};