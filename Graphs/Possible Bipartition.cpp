/*
Leetcode 886. Possible Bipartition
ques:-
Given a set of n people (numbered 1, 2, ..., n), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.
Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < dislikes.size(); i++)
        {
            graph[(dislikes[i][0] - 1)].push_back(dislikes[i][1] - 1);
            graph[(dislikes[i][1] - 1)].push_back(dislikes[i][0] - 1);
        }

        vector<int> visited(n, -1);
        queue<int> pendingNodes;

        for (int i = 0; i < n; i++)
        {
            if (visited[i] != -1)
                continue;

            pendingNodes.push(i);
            visited[i] = 1;
            int currset = 2;

            while (!pendingNodes.empty())
            {
                int size = pendingNodes.size();
                while (size--)
                {
                    int curr = pendingNodes.front();
                    pendingNodes.pop();
                    for (int i = 0; i < graph[curr].size(); i++)
                    {
                        if (visited[graph[curr][i]] == -1)
                        {
                            visited[graph[curr][i]] = currset;
                            pendingNodes.push(graph[curr][i]);
                        }
                        else
                        {
                            if (visited[curr] == visited[graph[curr][i]])
                                return false;
                        }
                    }
                }
                if (currset == 2)
                    currset = 1;
                else
                    currset = 2;
            }
        }

        return true;
    }
};