/*
Leetcode 188. Best Time to Buy and Sell Stock IV
ques:-
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> zerostockinhand(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> onestockinhand(n + 1, vector<int>(k + 1, INT_MIN));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                zerostockinhand[i][j] = max(zerostockinhand[i - 1][j], onestockinhand[i - 1][j] + prices[i - 1]);
                onestockinhand[i][j] = max(onestockinhand[i - 1][j], zerostockinhand[i - 1][j - 1] - prices[i - 1]);
            }
        }

        return zerostockinhand[n][k];
    }
};