/*
Leetcode 463. Island Perimeter
ques:-
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:

Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
Example 2:

Input: grid = [[1]]
Output: 4
Example 3:

Input: grid = [[1,0]]
Output: 4
*/

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int numones = 0;
        int subtracted = 0;
        for (int r = 0; r < grid.size(); ++r)
            for (int c = 0; c < grid[0].size(); ++c)
            {
                if (grid[r][c] == 0)
                    continue;
                numones++;
                if (r != 0 && grid[r - 1][c] == 1)
                    ++subtracted;
                if (c != 0 && grid[r][c - 1] == 1)
                    ++subtracted;
            }
        return 4 * numones - subtracted * 2;
    }
};