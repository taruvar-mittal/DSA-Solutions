/* gfg binary array sorting
ques:-
Given a binary array A[] of size N. The task is to arrange the array in increasing order.
Note: The binary array contains only 0  and 1.

Example 1:

Input: 
5
1 0 1 1 0

Output: 
0 0 1 1 1

Explanation: 
After arranging the elements in 
increasing order, elements will be as 
0 0 1 1 1.
Example 2:

Input:
10
1 0 1 1 1 1 1 0 0 0

Output: 
0 0 0 0 1 1 1 1 1 1

Explanation: 
After arranging the elements in 
increasing orde, elements will be 
0 0 0 0 1 1 1 1 1 1.
*/

void binSort(int arr[], int n)
{
    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] == 0)
        {
            arr[j] = 1;
            arr[i] = 0;
            i++;
            j++;
        }
        else
            j++;
    }
}