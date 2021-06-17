/*
Leetcode 42. Trapping Rain Water
ques:-
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int output = 0;
        int i = 0;
        int j = height.size() - 1;

        int leftmax = 0;
        int rightmax = 0;

        while (i < j)
        {
            leftmax = max(leftmax, height[i]);
            rightmax = max(rightmax, height[j]);

            if (leftmax < rightmax)
            {
                output += leftmax - height[i];
                i++;
            }
            else
            {
                output += rightmax - height[j];
                j--;
            }
        }

        return output;
    }
};