/*
Leetcode 1001. Grid Illumination
ques:-
There is a 2D grid of size n x n where each cell of this grid has a lamp that is initially turned off.

You are given a 2D array of lamp positions lamps, where lamps[i] = [rowi, coli] indicates that the lamp at grid[rowi][coli] is turned on. Even if the same lamp is listed more than once, it is turned on.

When a lamp is turned on, it illuminates its cell and all other cells in the same row, column, or diagonal.

You are also given another 2D array queries, where queries[j] = [rowj, colj]. For the jth query, determine whether grid[rowj][colj] is illuminated or not. After answering the jth query, turn off the lamp at grid[rowj][colj] and its 8 adjacent lamps if they exist. A lamp is adjacent if its cell shares either a side or corner with grid[rowj][colj].

Return an array of integers ans, where ans[j] should be 1 if the cell in the jth query was illuminated, or 0 if the lamp was not.

 

Example 1:


Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
Output: [1,0]
Explanation: We have the initial grid with all lamps turned off. In the above picture we see the grid after turning on the lamp at grid[0][0] then turning on the lamp at grid[4][4].
The 0th query asks if the lamp at grid[1][1] is illuminated or not (the blue square). It is illuminated, so set ans[0] = 1. Then, we turn off all lamps in the red square.

The 1st query asks if the lamp at grid[1][0] is illuminated or not (the blue square). It is not illuminated, so set ans[1] = 0. Then, we turn off all lamps in the red rectangle.

Example 2:

Input: n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
Output: [1,1]
Example 3:

Input: n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
Output: [1,1,0]
 

Constraints:

1 <= n <= 109
0 <= lamps.length <= 20000
0 <= queries.length <= 20000
lamps[i].length == 2
0 <= rowi, coli < n
queries[j].length == 2
0 <= rowj, colj < n
*/

class Solution
{
public:
    bool check(long long int x, long long int y, int n, unordered_map<long long int, long long int> &rows, unordered_map<long long int, long long int> &cols, unordered_map<long long int, long long int> &d1, unordered_map<long long int, long long int> &d2, unordered_map<long long int, long long int> &cellno)
    {
        return rows[x] > 0 || cols[y] > 0 || d1[x + y] > 0 || d2[x - y] > 0 || cellno[x * n + y] > 0;
    }

    void removal(long long int x, long long int y, int n, unordered_map<long long int, long long int> &rows, unordered_map<long long int, long long int> &cols, unordered_map<long long int, long long int> &d1, unordered_map<long long int, long long int> &d2, unordered_map<long long int, long long int> &cellno)
    {
        rows[x]--;
        cols[y]--;
        d1[x + y]--;
        d2[x - y]--;
        cellno[x * n + y]--;
    }

    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries)
    {
        unordered_map<long long int, long long int> rows;
        unordered_map<long long int, long long int> cols;
        unordered_map<long long int, long long int> d1;
        unordered_map<long long int, long long int> d2;
        unordered_map<long long int, long long int> cellno;

        for (auto v : lamps)
        {
            long long int i = v[0];
            long long int j = v[1];

            if (cellno[i * n + j])
                continue;

            rows[i]++;
            cols[j]++;
            d1[i + j]++;
            d2[i - j]++;
            cellno[i * n + j]++;
        }

        int q = queries.size();
        vector<int> output(q, false);

        for (int i = 0; i < q; i++)
        {
            long long int x = queries[i][0];
            long long int y = queries[i][1];

            if (check(x, y, n, rows, cols, d1, d2, cellno))
            {
                output[i] = true;
            }

            if (cellno[x * n + y] > 0)
                removal(x, y, n, rows, cols, d1, d2, cellno);

            if (x > 0 && y > 0 && cellno[(x - 1) * n + (y - 1)] > 0)
                removal(x - 1, y - 1, n, rows, cols, d1, d2, cellno);

            if (x > 0 && cellno[(x - 1) * n + (y)] > 0)
                removal(x - 1, y, n, rows, cols, d1, d2, cellno);

            if (x > 0 && y < n && cellno[(x - 1) * n + (y + 1)] > 0)
                removal(x - 1, y + 1, n, rows, cols, d1, d2, cellno);

            if (y < n && cellno[(x)*n + (y + 1)] > 0)
                removal(x, y + 1, n, rows, cols, d1, d2, cellno);

            if (x < n && y < n && cellno[(x + 1) * n + (y + 1)] > 0)
                removal(x + 1, y + 1, n, rows, cols, d1, d2, cellno);

            if (x < n && cellno[(x + 1) * n + (y)] > 0)
                removal(x + 1, y, n, rows, cols, d1, d2, cellno);

            if (x < n && y > 0 && cellno[(x + 1) * n + (y - 1)] > 0)
                removal(x + 1, y - 1, n, rows, cols, d1, d2, cellno);

            if (y > 0 && cellno[(x)*n + (y - 1)] > 0)
                removal(x, y - 1, n, rows, cols, d1, d2, cellno);
        }
        return output;
    }
};