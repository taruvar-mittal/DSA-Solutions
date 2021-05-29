/*
Leetcode 1202. Smallest String With Swaps
ques-
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
*/

class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        if (x == parent[x])
            return x;
        int temp = find(parent, parent[x]);
        parent[x] = temp;
        return temp;
    }

    void merge(vector<int> &parent, int x, int y)
    {
        int pox = find(parent, x);
        int poy = find(parent, y);

        if (pox == poy)
            return;

        parent[poy] = pox;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.length();
        vector<int> parent(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (auto v : pairs)
        {
            merge(parent, v[0], v[1]);
        }

        unordered_map<int, vector<int>> sets;

        for (int i = 0; i < n; i++)
        {
            sets[find(parent, i)].push_back(i);
        }

        for (auto it : sets)
        {
            vector<int> v = it.second;
            vector<char> setchars;
            for (int i = 0; i < v.size(); i++)
            {
                setchars.push_back(s[v[i]]);
            }
            sort(setchars.begin(), setchars.end());
            for (int i = 0; i < v.size(); i++)
            {
                s[v[i]] = setchars[i];
            }
        }
        return s;
    }
};