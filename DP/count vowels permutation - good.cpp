/*
Leetcode 1220. Count Vowels Permutation
ques:-
Given an integer n, your task is to count how many strings of length n can be formed under the following rules:

Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
Each vowel 'a' may only be followed by an 'e'.
Each vowel 'e' may only be followed by an 'a' or an 'i'.
Each vowel 'i' may not be followed by another 'i'.
Each vowel 'o' may only be followed by an 'i' or a 'u'.
Each vowel 'u' may only be followed by an 'a'.
Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
Example 2:

Input: n = 2
Output: 10
Explanation: All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
Example 3: 

Input: n = 5
Output: 68
*/

class Solution
{
public:
    int countVowelPermutation(int n)
    {
        vector<vector<long long>> dp(n, vector<long long>(5, 0));
        for (int i = 0; i < 5; i++)
        {
            dp[0][i] = 1;
        }
        int m = 1000000007;
        int a = 0, e = 1, i = 2, o = 3, u = 4;

        for (int j = 1; j < n; j++)
        {
            dp[j][a] += (dp[j - 1][e] % m + dp[j - 1][i] % m + dp[j - 1][u] % m) % m;
            dp[j][e] += (dp[j - 1][a] % m + dp[j - 1][i] % m) % m;
            dp[j][i] += (dp[j - 1][e] % m + dp[j - 1][o] % m) % m;
            dp[j][o] += dp[j - 1][i] % m;
            dp[j][u] += (dp[j - 1][i] % m + dp[j - 1][o] % m) % m;
        }

        long long output = 0;
        for (int x = 0; x < 5; x++)
        {
            output = (output % m + dp[n - 1][x] % m) % m;
        }

        return output % m;
    }
};