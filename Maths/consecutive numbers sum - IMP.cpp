/*
leetcode 829. Consecutive Numbers Sum
ques:-
Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.

Example 1:

Input: n = 5
Output: 2
Explanation: 5 = 2 + 3
Example 2:

Input: n = 9
Output: 3
Explanation: 9 = 4 + 5 = 2 + 3 + 4
Example 3:

Input: n = 15
Output: 4
Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
*/

class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        int count = 0;
        for (int k = 1; k < sqrt(2 * n); k++)
        {
            if ((n - (k * (k - 1) / 2)) % k == 0)
                count++;
        }
        return count;
    }
};