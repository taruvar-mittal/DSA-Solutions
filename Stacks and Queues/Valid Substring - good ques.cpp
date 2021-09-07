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
        stack<pair<char,int>> st;
        int ans = 0;
        
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c=='(') st.push({c,i});
            else{
                if(st.empty()) st.push({c,i});
                else if(st.top().first=='('){
                    st.pop();
                    if(st.empty()) ans = max(ans,i+1);
                    else ans = max(ans,i-st.top().second);
                }else 
                   st.push({c,i});
            }
        }
        
        return ans;
    }
};
