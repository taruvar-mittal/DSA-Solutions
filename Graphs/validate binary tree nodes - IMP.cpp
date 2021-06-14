/*
Leetcode 1361. Validate Binary Tree Nodes
ques:-
You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

Note that the nodes have no values and that we only use the node numbers in this problem.

 

Example 1:


Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
Output: true
Example 2:


Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
Output: false
Example 3:


Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
Output: false
Example 4:


Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
Output: false
*/

class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent, parent[x]);
    }

    void merge(vector<int> &parent, vector<int> &rank, int x, int y)
    {
        int pox = find(parent, x);
        int poy = find(parent, y);

        if (pox == poy)
            return;

        if (rank[pox] > rank[poy])
            parent[poy] = pox;
        else if (rank[poy] > rank[pox])
            parent[pox] = poy;
        else
        {
            parent[poy] = pox;
            rank[poy]++;
        }
    }

    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++)
        {

            if (leftChild[i] != -1)
            {
                if (find(parent, leftChild[i]) != leftChild[i] || find(parent, leftChild[i]) == find(parent, i))
                    return false;
                merge(parent, rank, i, leftChild[i]);
            }

            if (rightChild[i] != -1)
            {
                if (find(parent, rightChild[i]) != rightChild[i] || find(parent, rightChild[i]) == find(parent, i))
                    return false;
                merge(parent, rank, i, rightChild[i]);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
                count++;
        }

        return count == 1;
    }
};