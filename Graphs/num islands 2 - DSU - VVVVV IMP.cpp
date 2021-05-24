/*
Lintcode 434 · Number of Islands II
https://www.lintcode.com/problem/434/description

ques:-
Given a n,m which means the row and column of the 2D matrix and an array of pair A( size k). Originally, the 2D matrix is all 0 which means there is only sea in the matrix. The list pair has k operator and each operator has two integer A[i].x, A[i].y means that you can change the grid matrix[A[i].x][A[i].y] from sea to island. Return how many island are there in the matrix after each operator.You need to return an array of size K.

0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Example
Example 1:

Input: n = 4, m = 5, A = [[1,1],[0,1],[3,3],[3,4]]
Output: [1,1,2,2]
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
Example 2:

Input: n = 3, m = 3, A = [[0,0],[0,1],[2,2],[2,1]]
Output: [1,1,2,2]
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
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

    void dounion(vector<int> &parent, vector<int> &rank, int x, int y, int &islands)
    {
        int lox = find(x, parent);
        int loy = find(y, parent);

        if (lox == loy)
            return;

        islands--;
        if (rank[lox] > rank[loy])
            parent[loy] = lox;
        else if (rank[lox] < rank[loy])
            parent[lox] = loy;
        else
        {
            parent[lox] = loy;
            rank[loy]++;
        }
    }

    vector<int> numIslands2(int n, int m, vector<Point> &operators)
    {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<int> parent(n * m);
        for (int i = 0; i < n * m; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(n * m, 1);

        vector<int> output;
        int islands = 0;

        for (auto v : operators)
        {
            int i = v.x;
            int j = v.y;

            if (grid[i][j] == 1)
            {
                output.push_back(islands);
                continue;
            }

            grid[i][j] = 1;
            islands++;

            if (i - 1 >= 0 && grid[i - 1][j] == 1)
                dounion(parent, rank, i * m + j, (i - 1) * m + j, islands);
            if (j - 1 >= 0 && grid[i][j - 1] == 1)
                dounion(parent, rank, i * m + j, i * m + (j - 1), islands);
            if (i + 1 < n && grid[i + 1][j] == 1)
                dounion(parent, rank, i * m + j, (i + 1) * m + j, islands);
            if (j + 1 < m && grid[i][j + 1] == 1)
                dounion(parent, rank, i * m + j, i * m + (j + 1), islands);

            output.push_back(islands);
        }
        return output;
    }
};