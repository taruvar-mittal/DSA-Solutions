/*
GeeksforGeeks - negative weight cycle 
BELLMAN FORD ALGORITHM
ques:-
Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.
 
Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3,-1.
Example 2:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.
*/

class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        vector<int> output(n, INT_MAX);
        output[0] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < edges.size(); j++)
            {
                vector<int> v = edges[j];
                if (output[v[0]] == INT_MAX)
                    continue;
                else if (output[v[1]] > output[v[0]] + v[2])
                    output[v[1]] = output[v[0]] + v[2];
            }
        }

        for (int i = 0; i < edges.size(); i++)
        {
            if (output[edges[i][0]] == INT_MAX)
                continue;
            if (output[edges[i][1]] > output[edges[i][0]] + edges[i][2])
                return 1;
        }
        return 0;
    }
};