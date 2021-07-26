/*
Leetcode 516. Longest Palindromic Subsequence
ques:-
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
*/

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }
};

// method 2 - without LCS

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int gap = 2; gap <= n; gap++)
        {
            for (int left = 0; left <= n - gap; left++)
            {
                int right = left + gap - 1;

                if (gap == 2)
                    dp[left][right] = 1 + (s[left] == s[right]);
                else
                {

                    if (s[left] == s[right])
                        dp[left][right] = dp[left + 1][right - 1] + 2;
                    else
                        dp[left][right] = max(dp[left + 1][right], dp[left][right - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};