/*
gfg  - digit multiplier
Given a positive integer N, find the smallest number S such that the product of all the digits of S is equal to the number N. If there's no such number, Print "-1".

Example 1:

Input:
N = 100
Output:
455
Explanation:
4*5*5 = 100. There are no numbers
less than 455 with the product of
it's digit as 100.
Example 2:

Input:
N = 26
Output:
-1
Explanation:
There are no numbers which can form
a product of 26 with its digits.
*/

class Solution
{
public:
    string getSmallest(long long N)
    {
        if (N < 10)
            return to_string(N);
        string s = "";
        long long i;
        for (i = 9; i > 1; i--)
        {
            while (N % i == 0)
            {
                N = N / i;
                s = s + to_string(i);
            }
        }

        if (N > 10)
            return "-1";

        reverse(s.begin(), s.end());
        return s;
    }
};