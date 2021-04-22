/*
Leetcode 921 - Minimum add to make parenthesis valid
ques:-
Given a string S of '(' and ')' parentheses, we add the minimum number of parentheses ( '(' or ')', and in any positions ) so that the resulting parentheses string is valid.

Formally, a parentheses string is valid if and only if:

It is the empty string, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
Given a parentheses string, return the minimum number of parentheses we must add to make the resulting string valid.

Example 1:

Input: "())"
Output: 1
Example 2:

Input: "((("
Output: 3
Example 3:

Input: "()"
Output: 0
Example 4:

Input: "()))(("
Output: 4
*/

class Solution {
public:
    int minAddToMakeValid(string S) {
        if(S=="")
            return 0;
        int numopening = 0;
        int output = 0;
        for(int i=0;i<S.length();i++){
            if(S[i] == '(')
                numopening++;
            else{
                if(numopening>0)
                    numopening--;
                else
                    output++;
            }
        }
        return output+numopening;
    }
};
