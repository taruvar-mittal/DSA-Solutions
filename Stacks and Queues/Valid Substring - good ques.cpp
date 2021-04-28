/*
GeeksforGeeks - Valid Substring
ques:-
Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')', find out the length of the longest valid(well-formed) parentheses substring.
NOTE: Length of smallest the valid substring ( ) is 2.

Example 1:

Input: S = "(()("
Output: 2
Explanation: The longest valid 
substring is "()". Length = 2.
Example 2:

Input: S = "()(())("
Output: 6
Explanation: The longest valid 
substring is "()(())". Length = 6.
*/

class Solution {
  public:
    int findMaxLen(string s) {
        int maxlength = 0;
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(make_pair('(',i));
            }else{
                if(st.empty() || st.top().first==')'){
                    st.push(make_pair(')',i));
                }else{
                    pair<char,int> p = st.top();
                    st.pop();
                    if(st.empty())
                     maxlength = i+1;
                    else{
                        maxlength = max(maxlength,i-st.top().second);
                    }
                     
                }
            }
        }
        return maxlength;
    }
};
