/*
Leetcode 49. Group Anagrams
ques:-
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs)
        {
            vector<int> count(26, 0);
            for (auto c : s)
            {
                count[c - 'a']++;
            }
            string hash = "";
            for (int i = 0; i < 26; i++)
            {
                hash += to_string(count[i]);
                hash += '-';
            }
            mp[hash].push_back(s);
        }
        vector<vector<string>> output;
        for (auto it : mp)
        {
            output.push_back(it.second);
        }
        return output;
    }
};