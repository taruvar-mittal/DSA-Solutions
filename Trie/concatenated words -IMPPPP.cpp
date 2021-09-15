/*
leetcode 472. Concatenated Words
ques:-
Given an array of strings words (without duplicates), return all the concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

 

Example 1:

Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Example 2:

Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
*/

class Node
{
public:
    char ch;
    bool last;
    vector<Node *> children = vector<Node *>(26);

    Node(char ch)
    {
        this->ch = ch;
        this->last = false;
    }
};

class Solution
{
public:
    Node *root = new Node(' ');

    void addWord(string word)
    {
        Node *temp = root;
        for (auto t : word)
        {
            if (temp->children[t - 'a'] == NULL)
                temp->children[t - 'a'] = new Node(t);
            temp = temp->children[t - 'a'];
        }
        temp->last = true;
    }

    bool check(string word, int i, int count, vector<int> &dp)
    {
        if (i == word.length())
        {
            if (count >= 2)
                return true;
            else
                return false;
        }

        if (dp[i] != -1)
            return dp[i] == 0 ? false : true;

        Node *temp = root;
        for (int j = i; j < word.length(); j++)
        {
            if (temp->children[word[j] - 'a'] == NULL)
            {
                dp[i] = 0;
                return false;
            }

            temp = temp->children[word[j] - 'a'];

            if (temp->last)
            {
                bool temp2 = check(word, j + 1, count + 1, dp);
                if (temp2)
                {
                    dp[i] = 1;
                    return true;
                }
            }
        }

        dp[i] = 0;
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        for (auto word : words)
            addWord(word);

        vector<string> output;

        for (auto word : words)
        {
            vector<int> dp(word.length(), -1);
            if (check(word, 0, 0, dp))
                output.push_back(word);
        }
        return output;
    }
};