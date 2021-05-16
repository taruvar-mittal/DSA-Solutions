/*
GeeksforGeeks - BFS
ques:-
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.
Example 1:

Input:

Output: 0 1 2 3 4
Explanation: 
0 is connected to 1 , 2 , 3.
2 is connected to 4.
so starting from 0, it will go to 1 then 2
then 3.After this 2 to 4, thus bfs will be
0 1 2 3 4.
Example 2:

Input:

Output: 0 1 2
Explanation:
0 is connected to 1 , 2.
so starting from 0, it will go to 1 then 2,
thus bfs will be 0 1 2 3 4.
*/

class Solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        queue<int> pendingNodes;
        pendingNodes.push(0);
        visited[0] = true;
        vector<int> output;
        while (!pendingNodes.empty())
        {
            int size = pendingNodes.size();
            while (size--)
            {
                int currvertex = pendingNodes.front();
                output.push_back(currvertex);
                pendingNodes.pop();
                for (int i = 0; i < adj[currvertex].size(); i++)
                {
                    if (visited[adj[currvertex][i]] == false)
                    {
                        pendingNodes.push(adj[currvertex][i]);
                        visited[adj[currvertex][i]] = true;
                    }
                }
            }
        }
        return output;
    }
};