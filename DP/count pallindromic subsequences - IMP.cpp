/*
gfg Count Palindromic Subsequences 
ques:-
Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.
Note: You have to return the answer module 109+7;
 
Example 1:

Input: 
Str = "abcd"
Output: 
4
Explanation:
palindromic subsequence are : "a" ,"b", "c" ,"d"
 
Example 2:

Input: 
Str = "aab"
Output: 
4
Explanation:
palindromic subsequence are :"a", "a", "b", "aa"
*/

class Solution
{
public:
    /*You are required to complete below method */
    long long int countPS(string str)
    {
        int n = str.length();
        vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int gap = 2; gap <= n; gap++)
        {
            for (int left = 0; left <= n - gap; left++)
            {
                int right = left + gap - 1;

                if (str[left] == str[right])
                    dp[left][right] = (dp[left + 1][right] + dp[left][right - 1] + 1);
                else
                    dp[left][right] = (dp[left + 1][right] + dp[left][right - 1] - dp[left + 1][right - 1]);
            }
        }

        return dp[0][n - 1];
    }
};