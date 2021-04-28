/*
Leetcode 20 - Valid Parenthesis
ques:-
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='(' || c=='[' || c=='{')
                st.push(c);
            else{
                if(st.empty())
                    return false;
                char x = st.top();
                if((x=='('&&c!=')') || (x=='['&&c!=']') || (x=='{'&&c!='}'))
                    return false;
                st.pop();
            }
        }
        return st.size()==0;
    }
};
