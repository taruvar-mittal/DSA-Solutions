/*
Leetcode 233. Number of Digit One
ques:-
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.


Example 1:

Input: n = 13
Output: 6
Example 2:

Input: n = 0
Output: 0
*/

class Solution
{
public:
    int countDigitOne(int n)
    {
        long long count = 0;
        long long factor = 1;

        while (n / factor)
        {
            int suffix = n - (n / factor) * factor;
            int digit = (n / factor) % 10;
            int prefix = n / (factor * 10);

            if (digit > 1)
                count += (prefix + 1) * factor;
            else if (digit == 1)
                count += (prefix)*factor + (suffix + 1);
            else
                count += prefix * factor;

            factor *= 10;
        }

        return count;
    }
};