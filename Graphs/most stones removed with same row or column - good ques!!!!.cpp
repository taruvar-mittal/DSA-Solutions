/*
Leetcode 947. Most Stones Removed with Same Row or Column
ques:-
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
*/

// Method 1 - merging stones!
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

    void merge(vector<int> &parent, vector<int> &rank, int i, int j, int &numstones)
    {
        int par1 = find(parent, i);
        int par2 = find(parent, j);

        if (par1 == par2)
            return;

        numstones--;
        if (rank[par1] > rank[par2])
            parent[par2] = par2;
        else if (rank[par1] < rank[par2])
            parent[par1] = par2;
        else
        {
            parent[par1] = par2;
            rank[par1]++;
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(n, 1);
        int numstones = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    merge(parent, rank, i, j, numstones);
            }
        }
        return n - numstones;
    }
};

// method 2 - merging rows and columns - MORE EFFICIENT
//taking row as row and column as -column-1 for mapping
class Solution
{
public:
    int find(unordered_map<int, int> &parent, int x)
    {
        if (parent[x] == x)
            return x;
        int temp = find(parent, parent[x]);
        parent[x] = temp;
        return temp;
    }

    void merge(unordered_map<int, int> &parent, int row, int col, int &count)
    {
        int por = find(parent, row);
        int poc = find(parent, col);

        if (por == poc)
            return;

        count--;
        parent[por] = poc;
    }

    int removeStones(vector<vector<int>> &stones)
    {
        unordered_map<int, int> parent;
        int count = 0;

        for (auto v : stones)
        {
            int row = v[0];
            int col = v[1];
            if (parent.find(row) == parent.end())
            {
                parent[row] = row;
                count++;
            }
            if (parent.find(-col - 1) == parent.end())
            {
                parent[-col - 1] = -col - 1;
                count++;
            }
            merge(parent, row, -col - 1, count);
        }
        return stones.size() - count;
    }
};