/*
Leetcode 914. X of a Kind in a Deck of Cards
ques:-
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.
 

Example 1:

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
Example 3:

Input: deck = [1]
Output: false
Explanation: No possible partition.
Example 4:

Input: deck = [1,1]
Output: true
Explanation: Possible partition [1,1].
Example 5:

Input: deck = [1,1,2,2,2,2]
Output: true
Explanation: Possible partition [1,1],[2,2],[2,2].
*/

class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        int n = deck.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
        {
            freq[deck[i]]++;
        }
        int num = freq[deck[0]];
        for (auto it : freq)
        {
            num = __gcd(num, it.second);
        }
        return num > 1;
    }
};