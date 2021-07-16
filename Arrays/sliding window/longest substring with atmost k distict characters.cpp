/*
Lintcode 928 · Longest Substring with At Most Two Distinct Characters
ques:-
Description
Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

Example
Example 1
Input: “eceba”
Output: 3
Explanation:
T is "ece" which its length is 3.
Example 2
Input: “aaa”
Output: 3
*/

class Solution
{
public:
    int lengthOfLongestSubstringTwoDistinct(string &s)
    {
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int n = s.length();
        int output = 0;
        while (j < n)
        {
            mp[s[j]]++;
            while (mp.size() > 2)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            output = max(output, j - i + 1);
            j++;
        }
        return output;
    }
};