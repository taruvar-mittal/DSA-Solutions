/*
leetcode 211. Design Add and Search Words Data Structure
ques:-
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 

Example:

Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]

Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
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

class WordDictionary
{
public:
    /** Initialize your data structure here. */
    Node *root = new Node(' ');
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            char t = word[i];

            if (temp->children[t - 'a'] == NULL)
            {
                temp->children[t - 'a'] = new Node(t);
            }
            temp = temp->children[t - 'a'];
        }
        temp->last = true;
    }

    bool search(string word)
    {
        return search2(word, root);
    }

private:
    bool search2(string word, Node *node)
    {

        Node *temp = node;

        for (int i = 0; i < word.size(); i++)
        {
            char t = word[i];

            if (t == '.')
            {

                for (int j = 0; j < 26; j++)
                {
                    if (temp->children[j])
                    {
                        if (search2(word.substr(i + 1), temp->children[j]))
                            return true;
                    }
                }
                return false;
            }
            else
            {

                if (temp->children[t - 'a'] == NULL)
                {
                    temp->children[t - 'a'] = new Node(t);
                }
                temp = temp->children[t - 'a'];
            }
        }
        return temp->last;
    }
};