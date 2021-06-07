/*
GeeksforGeeks Subarrays with equal 1s and 0s 
ques:-
Given an array containing 0s and 1s. Find the number of subarrays having equal number of 0s and 1s.

Example 1:

Input:
n = 7
A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 
sub-arrays are: (0, 1), (2, 3), (0, 3), (3, 4), 
(4, 5) ,(2, 5), (0, 5), (1, 6)
Example 2:

Input:
n = 5
A[] = {1,1,1,1,0}
Output: 1
Explanation: The index range for the 
subarray is (3,4).
*/

class Solution
{
public:
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        int numzeroes = 0, numones = 0;
        long long int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                numzeroes++;
            else
                numones++;

            int num = numzeroes - numones;
            count += mp[num]++;
        }
        return count;
    }
};