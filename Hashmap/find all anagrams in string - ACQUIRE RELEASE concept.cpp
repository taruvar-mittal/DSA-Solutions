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
        unordered_map<char, int> p_mp;
        unordered_map<char, int> s_mp;

        for (int i = 0; i < p.length(); i++)
        {
            p_mp[p[i]]++;
        }
        int matchcount = 0;
        for (int i = 0; i < p.length(); i++)
        {
            s_mp[s[i]]++;
            if (s_mp[s[i]] <= p_mp[s[i]])
                matchcount++;
        }

        vector<int> output;

        if (matchcount == p.length())
            output.push_back(0);

        int i = 0;
        int j = p.length();

        while (j < s.length())
        {
            s_mp[s[j]]++;
            if (s_mp[s[j]] <= p_mp[s[j]])
                matchcount++;

            s_mp[s[i]]--;
            if (s_mp[s[i]] < p_mp[s[i]])
                matchcount--;

            i++;
            j++;

            if (matchcount == p.length())
                output.push_back(i);
        }
        return output;
    }
};