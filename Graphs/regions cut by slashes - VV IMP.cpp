/*
Leetcode 959. Regions Cut By Slashes
ques:-
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

Example 1:

Input: grid = [" /","/ "]
Output: 2
Example 2:

Input: grid = [" /","  "]
Output: 1
Example 3:

Input: grid = ["\\/","/\\"]
Output: 4
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
Example 4:

Input: grid = ["/\\","\\/"]
Output: 5
Explanation: (Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.)
Example 5:

Input: grid = ["//","/ "]
Output: 3
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

    void merge(int x, int y, vector<int> &parent, vector<int> &rank, int &cycles)
    {
        int parx = find(x, parent);
        int pary = find(y, parent);

        if (parx == pary)
        {
            cycles++;
            return;
        }

        if (rank[parx] > rank[pary])
            parent[pary] = parx;
        else if (rank[parx] < rank[pary])
            parent[parx] = pary;
        else
        {
            parent[parx] = pary;
            rank[pary]++;
        }
    }

    int regionsBySlashes(vector<string> &grid)
    {
        int n = grid.size();
        n++;

        vector<int> parent(n * n);
        for (int i = 0; i < n * n; i++)
        {
            parent[i] = i;
        }
        vector<int> rank(n * n, 1);

        // top row
        for (int j = 0; j < n; j++)
        {
            parent[j] = 0;
        }

        //bottom row
        for (int j = 0; j < n; j++)
        {
            parent[(n - 1) * n + j] = 0;
        }

        //front col;
        for (int j = 0; j < n; j++)
        {
            parent[n * j] = 0;
        }

        //last col
        for (int j = 0; j < n; j++)
        {
            parent[n * j + (n - 1)] = 0;
        }

        int cycles = 1;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (grid[i][j] == '\\')
                {
                    merge(i * n + j, (i + 1) * n + (j + 1), parent, rank, cycles);
                }
                else if (grid[i][j] == '/')
                {
                    merge(i * n + (j + 1), (i + 1) * n + j, parent, rank, cycles);
                }
            }
        }
        return cycles;
    }
};