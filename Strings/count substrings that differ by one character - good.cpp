/*
Leetcode 1638. Count Substrings That Differ by One Character
queS:-
Given two strings s and t, find the number of ways you can choose a non-empty substring of s and replace a single character by a different character such that the resulting substring is a substring of t. In other words, find the number of substrings in s that differ from some substring in t by exactly one character.

For example, the underlined substrings in "computer" and "computation" only differ by the 'e'/'a', so this is a valid way.

Return the number of substrings that satisfy the condition above.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aba", t = "baba"
Output: 6
Explanation: The following are the pairs of substrings from s and t that differ by exactly 1 character:
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
The underlined portions are the substrings that are chosen from s and t.
​​Example 2:
Input: s = "ab", t = "bb"
Output: 3
Explanation: The following are the pairs of substrings from s and t that differ by 1 character:
("ab", "bb")
("ab", "bb")
("ab", "bb")
​​​​The underlined portions are the substrings that are chosen from s and t.
Example 3:
Input: s = "a", t = "a"
Output: 0
Example 4:

Input: s = "abe", t = "bbc"
Output: 10
*/

class Solution
{
public:
    int countSubstrings(string s, string t)
    {
        int n = s.size(), m = t.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i] != t[j])
                {
                    int cnt1 = 0, cnt2 = 0;
                    int ips = i - 1, ipt = j - 1, ifs = i + 1, ift = j + 1;
                    while (ips >= 0 && ipt >= 0 && s[ips] == t[ipt])
                    {
                        cnt1++, ips--, ipt--;
                    }
                    while (ifs < n && ift < m && s[ifs] == t[ift])
                    {
                        cnt2++, ifs++, ift++;
                    }
                    ans += cnt1 * cnt2 + cnt1 + cnt2 + 1;
                }
            }
        }
        return ans;
    }
};