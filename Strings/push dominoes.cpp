/*
leetcode 838. Push Dominoes
ques:-
There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.


Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Example 2:


Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
*/

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        string temp = "L" + dominoes + "R";

        int i = 0;
        int j = 1;

        while (j < temp.length())
        {
            if (temp[j] == '.')
            {
                j++;
                continue;
            }

            char c1 = temp[i];
            char c2 = temp[j];

            if (c1 == 'L' && c2 == 'L')
            {
                for (int k = i + 1; k < j; k++)
                {
                    temp[k] = 'L';
                }
            }
            else if (c1 == 'R' && c2 == 'R')
            {
                for (int k = i + 1; k < j; k++)
                {
                    temp[k] = 'R';
                }
            }
            if (c1 == 'R' && c2 == 'L')
            {
                int x = i + 1;
                int y = j - 1;
                while (x < y)
                {
                    temp[x] = 'R';
                    temp[y] = 'L';
                    x++;
                    y--;
                }
            }

            i = j;
            j++;
        }

        string output = "";
        for (int i = 1; i < temp.length() - 1; i++)
        {
            output += temp[i];
        }

        return output;
    }
};