/*
gfg - anagram pallindrome
ques:-
Given a string S, Check if characters of the given string can be rearranged to form a palindrome. 

Example 1:

Input:
S = "geeksogeeks"
Output: Yes
Explanation: The string can be converted
into a palindrome: geeksoskeeg

â€‹Example 2:

Input: 
S = "geeksforgeeks"
Output: No
Explanation: The given string can't be
converted into a palindrome.
*/

int isPossible(string S)
{
    unordered_map<char, int> freq;
    for (int i = 0; i < S.length(); i++)
    {
        freq[S[i]]++;
    }
    int odds = 0;
    for (auto it : freq)
    {
        if (it.second % 2 != 0)
        {
            odds++;
            if (odds > 1)
                return 0;
        }
    }
    return 1;
}