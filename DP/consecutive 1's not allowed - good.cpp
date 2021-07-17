/*
gfg Consecutive 1's not allowed
ques:-
Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s. Output your answer modulo 10^9 + 7.

Example 1:

Input:
N = 3
Output: 5
Explanation: 5 strings are (000,
001, 010, 100, 101).
Example 2:

Input:
N = 2
Output: 3
Explanation: 3 strings are
(00,01,10).
*/

class Solution
{
public:
    // #define ll long long
    ll countStrings(int n)
    {
        if (n == 0)
            return 0;
        ll endwith0 = 1;
        ll endwith1 = 1;

        for (int i = 1; i < n; i++)
        {
            int total = (endwith0 + endwith1) % 1000000007;
            endwith1 = endwith0;
            endwith0 = total;
        }

        return (endwith0 % 1000000007 + endwith1 % 1000000007) % 1000000007;
    }
};