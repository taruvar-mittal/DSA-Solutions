/*
leetcode 1007. Minimum Domino Rotations For Equal Row
ques:-
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
*/

class Solution
{
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
    {
        int n = tops.size();
        if (n < 1)
            return -1;

        int x = tops[0];
        int y = bottoms[0];

        int topsxmin = 0, topsymin = 0, bottomsxmin = 0, bottomsymin = 0;

        for (int i = 0; i < n; i++)
        {
            if (topsxmin != INT_MAX)
            {
                if (tops[i] != x)
                {
                    if (bottoms[i] != x)
                        topsxmin = INT_MAX;
                    else
                        topsxmin++;
                }
            }
            if (topsymin != INT_MAX)
            {
                if (tops[i] != y)
                {
                    if (bottoms[i] != y)
                        topsymin = INT_MAX;
                    else
                        topsymin++;
                }
            }
            if (bottomsxmin != INT_MAX)
            {
                if (bottoms[i] != x)
                {
                    if (tops[i] != x)
                        bottomsxmin = INT_MAX;
                    else
                        bottomsxmin++;
                }
            }
            if (bottomsymin != INT_MAX)
            {
                if (bottoms[i] != y)
                {
                    if (tops[i] != y)
                        bottomsymin = INT_MAX;
                    else
                        bottomsymin++;
                }
            }
        }

        int ans = min(topsxmin, min(topsymin, min(bottomsxmin, bottomsymin)));
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};
