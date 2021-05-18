/*
Leetcode 1048. Longest String Chain
ques:-
Given a list of words, each word consists of English lowercase letters.

Let's say word1 is a predecessor of word2 if and only if we can add exactly one letter anywhere in word1 to make it equal to word2. For example, "abc" is a predecessor of "abac".

A word chain is a sequence of words [word_1, word_2, ..., word_k] with k >= 1, where word_1 is a predecessor of word_2, word_2 is a predecessor of word_3, and so on.

Return the longest possible length of a word chain with words chosen from the given list of words.

Example 1:

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chain is "a","ba","bda","bdca".
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
*/

class Solution
{
public:
    bool check(string word1, string word2)
    {
        if (word1.length() + 1 != word2.length())
            return false;

        int j = 0;
        bool newchar = false;
        for (int i = 0; i < word2.length(); i++)
        {
            if (word2[i] == word1[j])
                j++;
            else
            {
                if (newchar)
                    return false;
                newchar = true;
            }
        }
        return true;
    }

    static bool comp(string &a, string &b)
    {
        return a.length() < b.length();
    }

    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        if (n <= 1)
            return 0;

        sort(words.begin(), words.end(), comp);

        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word1 = words[j];
                string word2 = words[i];

                if (word2.length() == word1.length() + 1 && check(word1, word2))
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                    }
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};