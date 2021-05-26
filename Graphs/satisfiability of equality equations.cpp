/*
Leetcode 990. Satisfiability of Equality Equations
ques:-
Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

Example 1:

Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.
Example 2:

Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
Example 3:

Input: ["a==b","b==c","a==c"]
Output: true
Example 4:

Input: ["a==b","b!=c","c==a"]
Output: false
Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true
*/

class Solution
{
public:
    char find(unordered_map<char, char> &parent, char c)
    {
        if (c == parent[c])
            return c;
        char temp = find(parent, parent[c]);
        parent[c] = temp;
        return temp;
    }

    void merge(unordered_map<char, char> &parent, unordered_map<char, int> &rank, char c1, char c2)
    {
        char par1 = find(parent, c1);
        char par2 = find(parent, c2);

        if (par1 == par2)
            return;

        if (rank[par1] > rank[par2])
            parent[par2] = par1;
        else if (rank[par1] < rank[par2])
            parent[par1] = par2;
        else
        {
            parent[par2] = par1;
            rank[par1]++;
        }
    }

    bool equationsPossible(vector<string> &equations)
    {
        stack<string> notequals;

        unordered_map<char, char> parent;
        unordered_map<char, int> rank;

        for (auto s : equations)
        {
            if (s[1] == '!')
            {
                notequals.push(s);
                continue;
            }
            else
            {
                if (parent.find(s[0]) == parent.end())
                {
                    parent[s[0]] = s[0];
                    rank[s[0]] = 1;
                }
                if (parent.find(s[3]) == parent.end())
                {
                    parent[s[3]] = s[3];
                    rank[s[3]] = 1;
                }
                merge(parent, rank, s[0], s[3]);
            }
        }

        while (!notequals.empty())
        {
            string s = notequals.top();
            notequals.pop();
            if (s[0] == s[3])
                return false;
            if (parent.find(s[0]) == parent.end() || parent.find(s[3]) == parent.end())
                continue;
            if (find(parent, s[0]) == find(parent, s[3]))
                return false;
        }

        return true;
    }
};