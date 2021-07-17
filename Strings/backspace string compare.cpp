/*
Leetcode 844. Backspace String Compare
ques:-
Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

Note that after backspacing an empty text, the text will continue empty.

 

Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".
Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".
Example 3:

Input: s = "a##c", t = "#a#c"
Output: true
Explanation: Both s and t become "c".
Example 4:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
*/

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s1, s2;
        for (auto c : s)
        {
            if (c == '#' && !s1.empty())
                s1.pop();
            else if (c != '#')
                s1.push(c);
        }
        for (auto c : t)
        {
            if (c == '#' && !s2.empty())
                s2.pop();
            else if (c != '#')
                s2.push(c);
        }

        if (s1.size() != s2.size())
            return false;
        while (!s1.empty())
        {
            char c1 = s1.top();
            s1.pop();
            char c2 = s2.top();
            s2.pop();

            if (c1 != c2)
                return false;
        }
        return true;
    }
};