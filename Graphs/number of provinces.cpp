/*
Leetcode 547. Number of Provinces
ques:-
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Example 1:

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:

Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
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

    void merge(vector<int> &parent, vector<int> &rank, int i, int j, int &provinces)
    {
        int par1 = find(parent, i);
        int par2 = find(parent, j);

        if (par1 == par2)
            return;

        provinces--;
        if (rank[par1] > rank[par2])
            parent[par2] = par1;
        else if (rank[par1] < rank[par2])
            parent[par1] = par2;
        else
        {
            parent[par1] = par2;
            rank[par1]++;
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(n, 1);
        int provinces = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && isConnected[i][j] == 1)
                    merge(parent, rank, i, j, provinces);
            }
        }
        return provinces;
    }
};