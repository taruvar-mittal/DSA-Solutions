/*
Leetcode 1319. Number of Operations to Make Network Connected
ques:-
There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.

Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 

Example 1:

Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
Example 4:

Input: n = 5, connections = [[0,1],[0,2],[3,4],[2,3]]
Output: 0
*/

class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        if (x == parent[x])
            return x;
        int temp = find(parent, parent[x]);
        parent[x] = temp;
        return temp;
    }

    void merge(vector<int> &parent, vector<int> &rank, int x, int y)
    {
        int parx = find(parent, x);
        int pary = find(parent, y);

        if (parx == pary)
        {
            return;
        }

        if (rank[parx] > rank[pary])
            parent[pary] = parx;
        else if (rank[parx] < rank[pary])
            parent[parx] = pary;
        else
        {
            parent[pary] = parx;
            rank[parx]++;
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(n, 0);

        for (auto v : connections)
        {
            merge(parent, rank, v[0], v[1]);
        }

        int free = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                free++;
        }
        return free - 1;
    }
};