/*
gfg Find Pair Given Difference 
ques:-
Given an array Arr[] of size L and a number N, you need to write a program to find if there exists a pair of elements in the array whose difference is N.

Example 1:

Input:
L = 6, N = 78
arr[] = {5, 20, 3, 2, 5, 80}
Output: 1
Explanation: (2, 80) have difference of 78.
Example 2:

Input:
L = 5, N = 45
arr[] = {90, 70, 20, 80, 50}
Output: -1
Explanation: There is no pair with difference of 45.
*/

bool findPair(int arr[], int n, int x)
{
    if (n < 2)
        return false;
    sort(arr, arr + n);
    int i = 0, j = 1;

    while (j < n)
    {
        int diff = arr[j] - arr[i];
        if (diff == x)
            return true;
        else if (diff < x)
            j++;
        else
            i++;
    }

    return false;
}