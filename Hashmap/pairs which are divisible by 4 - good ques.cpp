/*
Leetcode Pairs which are Divisible by 4 
ques:-
Given an array, if ‘n’ positive integers, count the number of pairs of integers in the array that have the sum divisible by 4.

Example 1:

Input : Arr[] = {2, 2, 1, 7, 5}
Output : 3
Explanation:
(2,2), (1,7) and(7,5) are the 3 pairs.

Example 2:

Input : Arr[] = {2, 2, 3, 5, 6}
Output : 4
*/

class Solution
{
public:
    int count4Divisibiles(int arr[], int n)
    {
        int k = 4;
        unordered_map<int, int> mp;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int rem = arr[i] % k;
            if (rem == 0)
                count += mp[0];
            else
                count += mp[k - rem];
            mp[rem]++;
        }
        return count;
    }
};