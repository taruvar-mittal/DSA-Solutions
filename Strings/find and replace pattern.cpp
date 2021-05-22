/*
Leetcode 890. Find and Replace Pattern
ques:-
Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.
Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
*/

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> output;
        for (auto word : words)
        {
            unordered_map<char, char> m;
            unordered_set<char> visited;
            if (word.length() != pattern.length())
                continue;

            int i = 0;
            for (; i < word.length(); i++)
            {
                if (m.find(pattern[i]) == m.end() && visited.find(word[i]) == visited.end())
                {
                    m[pattern[i]] = word[i];
                    visited.insert(word[i]);
                }
                else
                {
                    if (word[i] != m[pattern[i]])
                        break;
                }
            }
            if (i == word.length())
                output.push_back(word);
        }
        return output;
    }
};