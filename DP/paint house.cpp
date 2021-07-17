/*
Lintcode 515 · Paint House
ques:-
Description
There are a row of n houses, each house can be painted with one of the three colors: red, blue or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color, and you need to cost the least. Return the minimum cost.

The cost of painting each house with a certain color is represented by a n x 3 cost matrix. For example, costs[0][0] is the cost of painting house 0 with color red; costs[1][2] is the cost of painting house 1 with color green, and so on... Find the minimum cost to paint all houses.
*/

class Solution
{
public:
    int minCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        if (n == 0)
            return 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int add = 0;
                if (j == 0)
                    add = min(costs[i - 1][1], costs[i - 1][2]);
                else if (j == 1)
                    add = min(costs[i - 1][0], costs[i - 1][2]);
                else
                    add = min(costs[i - 1][0], costs[i - 1][1]);
                costs[i][j] += add;
            }
        }

        int output = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            output = min(output, costs[n - 1][i]);
        }
        return output;
    }
};