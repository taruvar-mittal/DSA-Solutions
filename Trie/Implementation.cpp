/*
leetcode 208. Implement Trie (Prefix Tree)
ques:-
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

Example 1:

Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]

Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True
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

class Trie
{
public:
    Node *root = new Node(' ');
    Trie()
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            char t = word[i];
            if (temp->children[t - 'a'] == NULL)
            {
                Node *child = new Node(t);
                temp->children[t - 'a'] = child;
            }
            temp = temp->children[t - 'a'];
        }
        temp->last = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            char t = word[i];
            if (temp->children[t - 'a'] == NULL)
            {
                return false;
            }
            temp = temp->children[t - 'a'];
        }
        return temp->last == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            char t = word[i];
            if (temp->children[t - 'a'] == NULL)
            {
                return false;
            }
            temp = temp->children[t - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */