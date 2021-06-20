/*
Leetcode 438. Find All Anagrams in a String
ques:-
Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
 */

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        if (p.length() > s.length())
            return {};
        vector<int> pv(26, 0), sv(26, 0);
        for (int i = 0; i < p.length(); i++)
        {
            pv[p[i] - 'a']++;
            sv[s[i] - 'a']++;
        }

        vector<int> output;
        if (pv == sv)
            output.push_back(0);

        for (int i = p.length(); i < s.length(); i++)
        {
            sv[s[i] - 'a']++;
            sv[s[i - p.length()] - 'a']--;
            if (sv == pv)
            {
                output.push_back(i - p.length() + 1);
            }
        }

        return output;
    }
};