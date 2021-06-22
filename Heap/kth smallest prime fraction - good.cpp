/*
Leetcode 786. K-th Smallest Prime Fraction
ques:-
You are given a sorted integer array arr containing 1 and prime numbers, where all the integers of arr are unique. You are also given an integer k.

For every i and j where 0 <= i < j < arr.length, we consider the fraction arr[i] / arr[j].

Return the kth smallest fraction considered. Return your answer as an array of integers of size 2, where answer[0] == arr[i] and answer[1] == arr[j].

Example 1:

Input: arr = [1,2,3,5], k = 3
Output: [2,5]
Explanation: The fractions to be considered in sorted order are:
1/5, 1/3, 2/5, 1/2, 3/5, and 2/3.
The third fraction is 2/5.
Example 2:

Input: arr = [1,7], k = 1
Output: [1,7]
*/

class Solution
{
public:
#define p pair<double, pair<int, int>>
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            pq.push({double((double)arr[i] / (double)arr[n - 1]), {i, n - 1}});
        }
        int count = 0;
        while (!pq.empty())
        {
            p curr = pq.top();
            pq.pop();
            count++;
            int i = curr.second.first;
            int j = curr.second.second;
            if (count == k)
                return {arr[i], arr[j]};
            if (i + 1 != j)
            {
                pq.push({double((double)arr[i] / (double)arr[j - 1]), {i, j - 1}});
            }
        }
        return {-1};
    }
};
