/*
lintcode 912 · Best Meeting Point
ques:-
Description
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.

Example
Example 1:

Input:
[[1,0,0,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output:
6

Explanation:
The point `(0,2)` is an ideal meeting point, as the total travel distance of `2 + 2 + 2 = 6` is minimal. So return `6`.
Example 2:

Input:
[[1,1,0,0,1],[1,0,1,0,0],[0,0,1,0,1]]
Output:
14
*/

class Solution
{
public:
    /**
     * @param grid: a 2D grid
     * @return: the minimize travel distance
     */
    int minTotalDistance(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows;
        vector<int> cols;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    rows.push_back(i);
            }
        }

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                if (grid[i][j] == 1)
                    cols.push_back(j);
            }
        }

        int row = rows[rows.size() / 2];
        int col = cols[cols.size() / 2];

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans += abs(row - i) + abs(col - j);
                }
            }
        }

        return ans;
    }
};