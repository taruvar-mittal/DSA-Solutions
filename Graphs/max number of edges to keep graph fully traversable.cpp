/*
Leetcode 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
ques:-
Alice and Bob have an undirected graph of n nodes and 3 types of edges:

Type 1: Can be traversed by Alice only.
Type 2: Can be traversed by Bob only.
Type 3: Can by traversed by both Alice and Bob.
Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

Return the maximum number of edges you can remove, or return -1 if it's impossible for the graph to be fully traversed by Alice and Bob.


Example 1:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
Output: 2
Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
Example 2:

Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
Output: 0
Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
Example 3:

Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
Output: -1
Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
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

    void merge(vector<int> &parent, int x, int y)
    {
        int pox = find(parent, x);
        int poy = find(parent, y);

        if (pox == poy)
            return;

        parent[pox] = poy;
    }

    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0] > b[0];
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        sort(edges.begin(), edges.end(), comp);

        vector<int> parA(n);
        vector<int> parB(n);
        for (int i = 0; i < n; i++)
        {
            parA[i] = i;
            parB[i] = i;
        }

        int edge = 0;

        for (auto v : edges)
        {
            int type = v[0];
            int x = v[1] - 1;
            int y = v[2] - 1;

            if (type == 3)
            {
                if (find(parA, x) == find(parA, y) && find(parB, x) == find(parB, y))
                    edge++;
                else
                {
                    merge(parA, x, y);
                    merge(parB, x, y);
                }
            }
            else if (type == 1)
            {
                if (find(parA, x) == find(parA, y))
                    edge++;
                else
                    merge(parA, x, y);
            }
            else if (type == 2)
            {
                if (find(parB, x) == find(parB, y))
                    edge++;
                else
                    merge(parB, x, y);
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (find(parA, i - 1) != find(parA, i) || find(parB, i - 1) != find(parB, i))
                return -1;
        }
        return edge;
    }
};