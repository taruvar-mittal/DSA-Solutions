/*
gfg segregate 0s,1s and 2s
ques:-
Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

Example 1:

Input: 
N = 5
arr[]= {0 2 1 2 0}
Output:
0 0 1 2 2
Explanation:
0s 1s and 2s are segregated 
into ascending order.
Example 2:

Input: 
N = 3
arr[] = {0 1 0}
Output:
0 0 1
Explanation:
0s 1s and 2s are segregated 
into ascending order.
*/

void sort012(int arr[], int n)
{
    int i = 0, j = 0, k = n - 1;

    while (j <= k)
    {
        if (arr[j] == 1)
            j++;
        else if (arr[j] == 0)
        {
            arr[j] = 1;
            arr[i] = 0;
            i++;
            j++;
        }
        else
        {
            arr[j] = arr[k];
            arr[k] = 2;
            k--;
        }
    }
}