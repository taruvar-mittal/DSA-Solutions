/*
Leetcode 953. Verifying an Alien Dictionary
ques:-
In an alien language, surprisingly they also use english lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographicaly in this alien language.


Example 1:

Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
Output: true
Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
Example 2:

Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
Output: false
Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.
Example 3:

Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
Output: false
Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).
*/

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {

        for (int i = 1; i < words.size(); i++)
        {
            string word1 = words[i - 1];
            string word2 = words[i];
            int j = 0;
            while (j < word1.length() && j < word2.length())
            {
                if (word1[j] != word2[j])
                    break;
                j++;
            }
            if (j == word1.length())
                continue;
            if (j == word2.length())
                return false;
            if (order.find(word1[j]) > order.find(word2[j]))
                return false;
        }
        return true;
    }
};