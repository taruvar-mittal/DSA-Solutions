/*
GeeksforGeeks - check AP sequence
ques:-
Given an array of N integers. Write a program to check whether an arithmetic progression can be formed using all the given elements. 
 

Example 1:

Input:
N=4
arr[] = { 0,12,4,8 }
Output: YES
Explanation: Rearrange given array as
{0, 4, 8, 12}  which forms an
arithmetic progression.
Example 2:

Input:
N=4
arr[] = {12, 40, 11, 20}
Output: NO
 

Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function checkIsAP() that takes array arr and integer N as parameters and return true for "Yes" and false for "No".
*/

class Solution
{
public:
    bool checkIsAP(int arr[], int n)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push(arr[i]);
        }
        if (pq.size() < 2)
            return true;

        int first = pq.top();
        pq.pop();
        int d = pq.top() - first;
        int curr = first + d;

        while (!pq.empty())
        {
            if (pq.top() != curr)
                return false;
            pq.pop();
            curr += d;
        }

        return true;
    }
};