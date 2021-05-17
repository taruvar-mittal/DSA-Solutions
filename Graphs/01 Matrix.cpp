/*
Leetcode 542. 01 Matrix
ques:-
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
*/

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> output(n, vector<int>(m, -1));

        queue<pair<pair<int, int>, int>> pendingVertices;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    output[i][j] = 0;
                    pendingVertices.push({{i, j}, 0});
                }
            }
        }

        while (!pendingVertices.empty())
        {
            pair<pair<int, int>, int> curr = pendingVertices.front();
            pendingVertices.pop();
            pair<int, int> coordinates = curr.first;
            int xc = coordinates.first;
            int yc = coordinates.second;

            if (xc - 1 >= 0)
            {
                if (mat[xc - 1][yc] == 1 && output[xc - 1][yc] == -1)
                {
                    output[xc - 1][yc] = curr.second + 1;
                    pendingVertices.push({{xc - 1, yc}, curr.second + 1});
                }
            }
            if (xc + 1 < n)
            {
                if (mat[xc + 1][yc] == 1 && output[xc + 1][yc] == -1)
                {
                    output[xc + 1][yc] = curr.second + 1;
                    pendingVertices.push({{xc + 1, yc}, curr.second + 1});
                }
            }
            if (yc - 1 >= 0)
            {
                if (mat[xc][yc - 1] == 1 && output[xc][yc - 1] == -1)
                {
                    output[xc][yc - 1] = curr.second + 1;
                    pendingVertices.push({{xc, yc - 1}, curr.second + 1});
                }
            }
            if (yc + 1 < m)
            {
                if (mat[xc][yc + 1] == 1 && output[xc][yc + 1] == -1)
                {
                    output[xc][yc + 1] = curr.second + 1;
                    pendingVertices.push({{xc, yc + 1}, curr.second + 1});
                }
            }
        }
        return output;
    }
};