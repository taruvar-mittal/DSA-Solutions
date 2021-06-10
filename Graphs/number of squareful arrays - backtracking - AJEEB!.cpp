/*
Leetcode 996. Number of Squareful Arrays
ques:-
Given an array nums of non-negative integers, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.

Return the number of permutations of nums that are squareful.  Two permutations perm1 and perm2 differ if and only if there is some index i such that perm1[i] != perm2[i].

 

Example 1:

Input: nums = [1,17,8]
Output: 2
Explanation: 
[1,8,17] and [17,8,1] are the valid permutations.
Example 2:

Input: nums = [2,2,2]
Output: 1
*/

class Solution
{
public:
    int output = 0;

    bool check(int x, int y)
    {
        int temp = x + y;
        int temp2 = sqrt(temp);
        return temp2 * temp2 == temp;
    }

    void dfs(vector<int> &nums, vector<int> &curr, vector<bool> &visited, int n)
    {
        if (curr.size() == n)
        {
            output++;
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == true)
                continue;
            else
            {
                if ((i == 0 || visited[i - 1] || nums[i] != nums[i - 1]) && (curr.size() == 0 || check(nums[i], curr[curr.size() - 1])))
                {
                    visited[i] = true;
                    curr.push_back(nums[i]);
                    dfs(nums, curr, visited, n);
                    visited[i] = false;
                    curr.pop_back();
                }
            }
        }
    }

    int numSquarefulPerms(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(nums, curr, visited, n);
        return output;
    }
};