/*
Leetcode 684. Redundant Connection
ques:-
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Example 1:

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:

Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
*/

class Solution
{
public:
    int find(int x, vector<int> &parent)
    {
        if (x == parent[x])
            return x;
        int temp = find(parent[x], parent);
        parent[x] = temp;
        return temp;
    }

    void merge(vector<int> &parent, vector<int> &rank, int x, int y)
    {
        int pox = find(x, parent);
        int poy = find(y, parent);

        if (rank[pox] > rank[poy])
            parent[poy] = pox;
        else if (rank[pox] < rank[poy])
            parent[pox] = poy;
        else
        {
            parent[pox] = poy;
            rank[pox]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(n, 0);

        for (auto v : edges)
        {
            if (find(v[0] - 1, parent) == find(v[1] - 1, parent))
                return v;

            merge(parent, rank, v[0] - 1, v[1] - 1);
        }
        return {-1, -1};
    }
};