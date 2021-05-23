/* 
Leetcode 51. N-Queens
ques:-
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
*/

class Solution
{
public:
    vector<vector<string>> output;

    bool check(vector<string> &curr, int row, int col, int n)
    {
        for (int i = row; i >= 0; i--)
        {
            if (curr[i][col] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        {
            if (curr[i][j] == 'Q')
                return false;
        }

        for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        {
            if (curr[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void dfs(vector<string> &curr, int row, int n)
    {
        if (row == n)
        {
            output.push_back(curr);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (check(curr, row, i, n))
            {
                curr[row][i] = 'Q';
                dfs(curr, row + 1, n);
                curr[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> curr(n, string(n, '.'));
        dfs(curr, 0, n);
        return output;
    }
};