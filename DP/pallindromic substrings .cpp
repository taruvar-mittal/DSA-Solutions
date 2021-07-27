/*
Leetcode 647. Palindromic Substrings
ques:-
Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

class Solution
{
public:
    int countSubstrings(string s)
    {
        int n = s.length();
        int count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true;
            count++;
        }

        for (int gap = 2; gap <= n; gap++)
        {
            for (int i = 0; i <= n - gap; i++)
            {
                int j = i + gap - 1;
                if (gap == 2)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = true;
                        count++;
                    }
                }
                else
                {
                    if (s[i] == s[j])
                    {
                        if (dp[i + 1][j - 1])
                        {
                            dp[i][j] = true;
                            count++;
                        }
                    }
                }
            }
        }

        return count;
    }
};