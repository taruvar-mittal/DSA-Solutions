/*
GeeksforGeeks - Minimum Swaps required to sort the array
ques:-
Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.

Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
Example 2:

Input:
nums = {10, 19, 6, 3, 5}
Output:
2
Explaination:
swap 10 with 3 and swap 19 with 5.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSwaps() which takes the nums as input parameter and returns an integer denoting the minimum number of swaps required to sort the array. If the array is already sorted, return 0.
*/

class Solution
{
public:
    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        return a.first < b.first;
    }

    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end(), comp);

        for (int i = 0; i < n; i++)
        {
            if (v[v[i].second].first == v[i].first)
            {
                swap(v[i], v[v[i].second]);
            }
        }

        vector<bool> visited(n, false);

        int swaps = 0;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            int currcycle = 0;

            int currvertex = i;
            while (visited[currvertex] == false)
            {
                visited[currvertex] = true;
                currcycle++;
                currvertex = v[currvertex].second;
            }

            swaps += currcycle - 1;
        }

        return swaps;
    }
};