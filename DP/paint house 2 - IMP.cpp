/*
Lintcode 516 · Paint House II
ques:-
Description
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
*/

class Solution
{
public:
    int minCostII(vector<vector<int>> &costs)
    {
        int n = costs.size();
        if (n == 0)
            return 0;
        int k = costs[0].size();

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for (int i = 0; i < k; i++)
        {
            if (costs[0][i] < min1)
            {
                min2 = min1;
                min1 = costs[0][i];
            }
            else if (costs[0][i] < min2)
                min2 = costs[0][i];
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (costs[i - 1][j] == min1)
                    costs[i][j] += min2;
                else
                    costs[i][j] += min1;
            }
            min1 = INT_MAX;
            min2 = INT_MAX;

            for (int j = 0; j < k; j++)
            {
                if (costs[i][j] < min1)
                {
                    min2 = min1;
                    min1 = costs[i][j];
                }
                else if (costs[i][j] < min2)
                    min2 = costs[i][j];
            }
        }

        int output = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            output = min(output, costs[n - 1][i]);
        }
        return output;
    }
};