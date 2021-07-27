/*
Leetcode 730. Count Different Palindromic Subsequences
ques:-
Given a string s, return the number of different non-empty palindromic subsequences in s. Since the answer may be very large, return it modulo 109 + 7.

A subsequence of a string is obtained by deleting zero or more characters from the string.

A sequence is palindromic if it is equal to the sequence reversed.

Two sequences a1, a2, ... and b1, b2, ... are different if there is some i for which ai != bi.

 

Example 1:

Input: s = "bccb"
Output: 6
Explanation: The 6 different non-empty palindromic subsequences are 'b', 'c', 'bb', 'cc', 'bcb', 'bccb'.
Note that 'bcb' is counted only once, even though it occurs twice.
Example 2:

Input: s = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba"
Output: 104860361
Explanation: There are 3104860382 different non-empty palindromic subsequences, which is 104860361 modulo 109 + 7.
*/

class Solution
{
public:
    int countPalindromicSubsequences(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int gap = 2; gap <= n; gap++)
        {
            for (int i = 0; i <= n - gap; i++)
            {
                int j = i + gap - 1;

                if (s[i] == s[j])
                {
                    int low = i + 1;
                    int high = j - 1;

                    while (low <= high && s[low] != s[i])
                        low++;
                    while (low <= high && s[high] != s[i])
                        high--;

                    if (low > high)
                    {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                    }
                    else if (low == high)
                    {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                    }
                    else
                    {
                        dp[i][j] = 2 * dp[i + 1][j - 1] - dp[low + 1][high - 1];
                    }
                }
                else
                {
                    dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                }

                dp[i][j] = (dp[i][j] < 0 ? dp[i][j] + 1000000007 : dp[i][j]) % 1000000007;
            }
        }

        return dp[0][n - 1];
    }
};