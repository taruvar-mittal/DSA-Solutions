/*
Leetcode 931. Minimum Falling Path Sum
ques:-
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum underlined below:
[[2,1,3],      [[2,1,3],
 [6,5,4],       [6,5,4],
 [7,8,9]]       [7,8,9]]
Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is underlined below:
[[-19,57],
 [-40,-5]]
Example 3:

Input: matrix = [[-48]]
Output: -48
*/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum1 = INT_MAX, sum2 = INT_MAX, sum3 = INT_MAX;
                if (j - 1 >= 0)
                    sum1 = matrix[i][j] + matrix[i - 1][j - 1];
                sum2 = matrix[i][j] + matrix[i - 1][j];
                if (j + 1 < n)
                    sum3 = matrix[i][j] + matrix[i - 1][j + 1];
                matrix[i][j] = min(sum1, min(sum2, sum3));
            }
        }

        int output = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            output = min(output, matrix[n - 1][i]);
        }
        return output;
    }
};