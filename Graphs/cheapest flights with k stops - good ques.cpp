/*
Leetcode 787. Cheapest Flights Within K Stops
ques:-
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

1 <= n <= 100
0 <= flights.length <= (n * (n - 1) / 2)
flights[i].length == 3
0 <= fromi, toi < n
fromi != toi
1 <= pricei <= 104
There will not be any multiple flights between two cities.
0 <= src, dst, k < n
src != dst
*/

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        sort(flights.begin(), flights.end(), comp);

        vector<int> prev(n, INT_MAX);
        vector<int> curr(n, INT_MAX);

        prev[src] = 0;

        for (int i = 0; i < k + 1; i++)
        {
            for (auto x : flights)
            {
                int u = x[0];
                int v = x[1];
                int w = x[2];

                if (prev[u] == INT_MAX)
                    continue;
                else if (prev[u] + w < curr[v])
                    curr[v] = prev[u] + w;
            }
            prev = curr;
        }

        if (curr[dst] == INT_MAX)
            return -1;

        return curr[dst];
    }
};