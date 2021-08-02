/*
gfg Largest Sum Subarray of Size at least K 
ques:-
Given an array and a number k, find the largest sum of the subarray containing at least k numbers. It may be assumed that the size of array is at-least k.
 

Example 1:

Input : 
n = 4
arr[] = {-4, -2, 1, -3}
k = 2
Output : 
-1
Explanation :
The sub array is {-2, 1}
 
Example 2:
Input :
n = 6 
arr[] = {1, 1, 1, 1, 1, 1}
k = 2
Output : 
6
Explanation :
The sub array is {1, 1, 1, 1, 1, 1}
*/

long long int maxSumWithK(long long int arr[], long long int n, long long int k)
{
    vector<long long int> kadane_sum(n);
    long long int currsum = 0;
    for (long long int i = 0; i < n; i++)
    {
        currsum += arr[i];
        kadane_sum[i] = currsum;
        if (currsum < 0)
            currsum = 0;
    }

    long long int i = 0, j = i + k - 1;
    long long int output = INT_MIN;
    long long int wsum = 0;
    for (long long int x = i; x <= j; x++)
    {
        wsum += arr[x];
    }
    currsum = wsum;
    output = currsum;
    i++;
    j++;
    while (j < n)
    {
        wsum -= arr[i - 1];
        wsum += arr[j];
        currsum = wsum;
        if (kadane_sum[i - 1] > 0)
            currsum += kadane_sum[i - 1];

        output = max(output, currsum);
        i++;
        j++;
    }
    return output;
}