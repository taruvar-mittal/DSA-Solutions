/*
 leetcode 3. Longest Substring Without Repeating Characters
 ques:-
 Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int output = 0;

        while (j < s.length())
        {
            if (mp.find(s[j]) != mp.end())
            {
                i = max(i, mp[s[j]] + 1);
            }
            mp[s[j]] = j;
            output = max(output, j - i + 1);
            j++;
        }
        return output;
    }
};