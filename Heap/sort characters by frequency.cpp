/*
Leetcode 451. Sort Characters By Frequency
ques:-
Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        unordered_map<char, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto it : freq)
        {
            pq.push({it.second, it.first});
        }
        string output = "";
        while (!pq.empty())
        {
            pair<int, char> curr = pq.top();
            pq.pop();
            for (int i = 0; i < curr.first; i++)
            {
                output += curr.second;
            }
        }
        return output;
    }
};