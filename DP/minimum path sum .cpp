/*
Leetcode 64. Minimum Path Sum
ques:-
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
*/

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                    continue;
                int right = INT_MAX, bottom = INT_MAX;
                if (i + 1 < m)
                    bottom = grid[i + 1][j];
                if (j + 1 < n)
                    right = grid[i][j + 1];
                grid[i][j] += min(bottom, right);
            }
        }

        return grid[0][0];
    }
};