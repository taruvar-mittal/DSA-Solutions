/*
Leetcode 218. The Skyline Problem
ques:-
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]

Example 1:

Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
Explanation:
Figure A shows the buildings of the input.
Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
Example 2:

Input: buildings = [[0,2,3],[2,5,3]]
Output: [[0,3],[5,0]]
*/

class Solution
{
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return (a[0] < b[0]) || (a[0] == b[0] && a[1] > b[1]);
    }

    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> points;

        for (int i = 0; i < buildings.size(); i++)
        {
            points.push_back({buildings[i][0], buildings[i][2]});
            points.push_back({buildings[i][1], -buildings[i][2]});
        }

        sort(points.begin(), points.end(), comp);

        multiset<int> pq;
        vector<vector<int>> output;
        int prev = 0;

        for (auto v : points)
        {
            int height = v[1];

            if (height > 0)
            {
                pq.insert(height);
                prev = *pq.rbegin();
                if (height == prev)
                    output.push_back(v);
            }
            else
            {
                pq.erase(pq.find(-height));
                if (prev == -height)
                {
                    if (!pq.empty())
                        prev = *pq.rbegin();
                    else
                        prev = 0;

                    output.push_back({v[0], prev});
                }
            }
        }

        vector<vector<int>> ans;

        for (int i = 0; i < output.size(); i++)
        {
            if (i == 0 || i == output.size() - 1)
                ans.push_back(output[i]);
            else
            {
                if (output[i][1] != output[i - 1][1])
                    ans.push_back(output[i]);
            }
        }

        return ans;
    }
};