/*
Leetcode 76. Minimum Window Substring
ques:-
Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> t_mp;
        for (int i = 0; i < t.length(); i++)
        {
            t_mp[t[i]]++;
        }

        unordered_map<char, int> s_mp;
        int matchcount = 0;
        int output = INT_MAX;
        int start = -1;

        int i = 0;
        int j = 0;

        while (j < s.length())
        {
            s_mp[s[j]]++;
            if (s_mp[s[j]] <= t_mp[s[j]])
                matchcount++;
            while (matchcount == t.length())
            {
                output = min(output, j - i + 1);
                if (output == j - i + 1)
                {
                    start = i;
                }
                s_mp[s[i]]--;
                if (s_mp[s[i]] < t_mp[s[i]])
                    matchcount--;
                i++;
            }
            j++;
        }

        if (start != -1)
            return s.substr(start, output);
        else
            return "";
    }
};