/*
Leetcode 685. Redundant Connection II
ques:-
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.

Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:

Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:

Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
Output: [4,1]
*/

class Solution
{
public:
    vector<int> edge;
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

        if (rank[parx] > rank[pary])
            parent[pary] = parx;
        else if (rank[parx] < rank[pary])
            parent[parx] = pary;
        else
        {
            parent[parx] = pary;
            rank[parx]++;
        }
    }

    bool checkDSU(vector<vector<int>> &edges, int n, vector<int> &blacklist)
    {
        vector<int> parent(n + 1);
        for (int i = 0; i < n + 1; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(n + 1, 1);

        for (int i = 0; i < edges.size(); i++)
        {
            if (blacklist.size() > 0 && edges[i] == blacklist)
                continue;

            if (find(parent, edges[i][0]) == find(parent, edges[i][1]))
            {
                edge = edges[i];
                return true;
            }
            else
                merge(parent, rank, edges[i][0], edges[i][1]);
        }

        return false;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> indegree(n + 1, -1);

        for (int i = 0; i < edges.size(); i++)
        {
            if (indegree[edges[i][1]] != -1)
            {
                vector<int> blacklist = edges[i];
                if (checkDSU(edges, n, blacklist))
                    return edges[indegree[edges[i][1]]];
                else
                    return blacklist;
            }
            else
            {
                indegree[edges[i][1]] = i;
            }
        }

        vector<int> noblacklist;
        checkDSU(edges, n, noblacklist);
        return edge;
    }
};