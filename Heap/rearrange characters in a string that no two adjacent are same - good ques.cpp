/*
Geeks for Geeks - Rearrange characters in a string such that no two adjacent are same
ques:-
Given a string with repeated characters, the task is to rearrange characters in a string so that no two adjacent characters are same.
Note : It may be assumed that the string has only lowercase English alphabets.
Examples: 
 

Input: aaabc 
Output: abaca 

Input: aaabb
Output: ababa 

Input: aa 
Output: Not Possible

Input: aaaabc 
Output: Not Possible
*/

#include <bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i]]++;
    }
    priority_queue<pair<int, char>> pq;
    for (auto it : freq)
    {
        pq.push({it.second, it.first});
    }
    pair<int, char> blacklist = pq.top();
    blacklist.first--;
    pq.pop();

    while (!pq.empty())
    {
        pair<int, char> curr = pq.top();
        pq.pop();
        if (blacklist.first > 0)
        {
            pq.push(blacklist);
        }
        blacklist = {curr.first - 1, curr.second};
    }
    return blacklist.first == 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}