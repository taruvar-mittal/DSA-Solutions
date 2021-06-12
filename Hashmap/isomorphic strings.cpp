/*
Leetcode 205. Isomorphic Strings
ques:-
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
*/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        int m = s.length();
        int n = t.length();

        if (m != n)
            return false;
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < m; i++)
        {
            int c1 = s[i];
            int c2 = t[i];
            if ((mp1.find(c1) != mp1.end() && mp1[c1] != c2) || (mp2.find(c2) != mp2.end() && mp2[c2] != c1))
                return false;
            mp1[c1] = c2;
            mp2[c2] = c1;
        }
        return true;
    }
};