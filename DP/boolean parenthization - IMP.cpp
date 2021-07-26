/*
Lintcode 725 · Boolean Parenthesization
ques:-
Given a boolean expression with following symbols.

Symbols
    'T' ---> true 
    'F' ---> false 
And following operators filled between symbols

Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR 
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Let the input be in form of two arrays one contains the symbols (T and F) in order and other contains operators (&, | and ^}

Example
Example 1:

Input： ['T', 'F', 'T']，['^', '&']
Output：2
Explanation：
The given expression is "T ^ F & T", it evaluates true, in two ways "((T ^ F) & T)" and "(T ^ (F & T))"
Example 2:

Input：['T', 'F', 'F']，['^', '|']
Output：2
Explanation：
The given expression is "T ^ F | F", it evaluates true, in
*/

class Solution
{
public:
    int countParenth(string &symb, string &oper)
    {
        int n = symb.length();
        int m = oper.length();

        vector<vector<int>> truedp(n, vector<int>(n, 0));
        vector<vector<int>> falsedp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            if (symb[i] == 'T')
            {
                truedp[i][i] = 1;
                falsedp[i][i] = 0;
            }
            else
            {
                truedp[i][i] = 0;
                falsedp[i][i] = 1;
            }
        }

        for (int gap = 2; gap <= n; gap++)
        {
            for (int left = 0; left <= n - gap; left++)
            {
                int right = left + gap - 1;
                for (int k = left; k < right; k++)
                {
                    char op = oper[k];
                    if (op == '&')
                    {
                        truedp[left][right] += truedp[left][k] * truedp[k + 1][right];
                        falsedp[left][right] += truedp[left][k] * falsedp[k + 1][right] + falsedp[left][k] * truedp[k + 1][right] + falsedp[left][k] * falsedp[k + 1][right];
                    }
                    else if (op == '|')
                    {
                        falsedp[left][right] += falsedp[left][k] * falsedp[k + 1][right];
                        truedp[left][right] += truedp[left][k] * falsedp[k + 1][right] + falsedp[left][k] * truedp[k + 1][right] + truedp[left][k] * truedp[k + 1][right];
                    }
                    else if (op == '^')
                    {
                        falsedp[left][right] += falsedp[left][k] * falsedp[k + 1][right] + truedp[left][k] * truedp[k + 1][right];
                        truedp[left][right] += truedp[left][k] * falsedp[k + 1][right] + falsedp[left][k] * truedp[k + 1][right];
                    }
                }
            }
        }

        return truedp[0][n - 1];
    }
};