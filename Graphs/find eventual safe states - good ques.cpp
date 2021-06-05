/*
Leetcode 802. Find Eventual Safe States
ques:-
We start at some node in a directed graph, and every turn, we walk along a directed edge of the graph. If we reach a terminal node (that is, it has no outgoing directed edges), we stop.

We define a starting node to be safe if we must eventually walk to a terminal node. More specifically, there is a natural number k, so that we must have stopped at a terminal node in less than k steps for any choice of where to walk.

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

The directed graph has n nodes with labels from 0 to n - 1, where n is the length of graph. The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph, going from node i to node j.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
 

Constraints:

n == graph.length
1 <= n <= 104
0 <= graph[i].legnth <= n
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 104].
*/

class Solution
{
public:
    unordered_set<int> safenodes;
    unordered_set<int> cyclenodes;

    bool dfs(vector<vector<int>> &graph, int i, unordered_set<int> &visited)
    {
        if (safenodes.find(i) != safenodes.end())
            return true;
        if (cyclenodes.find(i) != cyclenodes.end())
            return false;

        if (visited.find(i) != visited.end())
        {
            cyclenodes.insert(i);
            return false;
        }

        visited.insert(i);
        for (int v = 0; v < graph[i].size(); v++)
        {
            if (!dfs(graph, graph[i][v], visited))
            {
                cyclenodes.insert(i);
                return false;
            }
        }

        safenodes.insert(i);
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> output;
        unordered_set<int> visited;

        for (int i = 0; i < graph.size(); i++)
        {
            if (dfs(graph, i, visited))
                output.push_back(i);
        }

        return output;
    }
};