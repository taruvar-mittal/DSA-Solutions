/*
Leetcode 733. Flood Fill
ques:-
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
*/

class Solution
{
public:
    void dfs(vector<vector<int>> &image, vector<vector<int>> &output, int sr, int sc, int newColor, int currColor, int n, int m)
    {
        if (sr < 0 || sr >= n || sc < 0 || sc >= m || output[sr][sc] != -1)
            return;

        if (image[sr][sc] == currColor)
            output[sr][sc] = newColor;
        else
            return;

        dfs(image, output, sr - 1, sc, newColor, currColor, n, m);
        dfs(image, output, sr, sc - 1, newColor, currColor, n, m);
        dfs(image, output, sr + 1, sc, newColor, currColor, n, m);
        dfs(image, output, sr, sc + 1, newColor, currColor, n, m);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> output(n, vector<int>(m, -1));
        dfs(image, output, sr, sc, newColor, image[sr][sc], n, m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (output[i][j] == -1)
                    output[i][j] = image[i][j];
            }
        }
        return output;
    }
};