/*
Lintcode 514 · Paint Fence
ques:-
Description
There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.
*/

class Solution
{
public:
    int numWays(int n, int k)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return k;
        int last2same = k;
        int last2diff = k * (k - 1);
        for (int i = 2; i < n; i++)
        {
            int total = last2same + last2diff;
            last2same = last2diff;
            last2diff = total * (k - 1);
        }
        return last2same + last2diff;
    }
};