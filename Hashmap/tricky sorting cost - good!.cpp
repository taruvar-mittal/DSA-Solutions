/*
GeekforGeeks - Tricky Sorting Cost 
ques:-
Given an array arr[] of N elements containing first N positive integers. You have to sort the integers in ascending order by the following operation. Operation is to pick an integer and place it at end or at start. Every such operation increases cost by one. The task is to sort the array in the minimum cost

Example 1:

Input: N = 3
arr = {2, 1, 3}
Output: 1
Explaination: Place 1 at start.
Example 2:

Input: N = 4
arr = {4, 3, 1, 2}
Output: 2
Explaination: First place 3 at end then 
4 at end.
*/

class Solution
{
public:
    int sortingCost(int N, int arr[])
    {
        unordered_map<int, int> mp;
        int len = 0;
        for (int i = 0; i < N; i++)
        {
            if (mp.count(arr[i] - 1))
            {
                mp[arr[i]] = mp[arr[i] - 1] + 1;
            }
            else
            {
                mp[arr[i]] = 1;
            }
            len = max(len, mp[arr[i]]);
        }

        return N - len;
    }
};