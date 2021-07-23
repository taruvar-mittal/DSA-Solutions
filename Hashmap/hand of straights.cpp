/*
Leetcode 846. Hand of Straights
ques":-
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

*/

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> mp;
        for (auto h : hand)
        {
            mp[h]++;
        }

        while (mp.size() > 0)
        {
            int start = mp.begin()->first;
            for (int i = start; i < start + groupSize; i++)
            {
                if (mp.find(i) == mp.end())
                    return false;
                if (mp.find(i)->second == 1)
                    mp.erase(i);
                else
                    mp.find(i)->second--;
            }
        }

        return true;
    }
};