/*
count minimum number of reversals to make expression valid
ques:-
Given a string S consisting of only opening and closing curly brackets '{' and '}', find out the minimum number of reversals required to convert the string into a balanced expression.
A reversal means changing '{' to '}' or vice-versa.

Example 1:

Input:
S = "}{{}}{{{"
Output: 3
Explanation: One way to balance is:
"{{{}}{}}". There is no balanced sequence
that can be formed in lesser reversals.
â€‹Example 2:

Input: 
S = "{{}{{{}{{}}{{"
Output: -1
Explanation: There's no way we can balance
this sequence of braces.
*/

int countRev (string s)
{
    int n = s.length();
    if(n%2!=0)
     return -1;
    
    stack<char> st;
    for(auto c:s){
        if(st.empty() || c=='{')
          st.push(c);
        else{
            if(st.top()=='{')
             st.pop();
            else
              st.push(c);
        }
    }
    int cp = 0,op =0;
    while(!st.empty()){
        if(st.top()=='{')
        op++;
        else
        cp++;
        
        st.pop();
    }
    
    if((op%2==0 && cp%2!=0) || (op%2!=0 && cp%2==0))
      return -1;
    else if(cp%2==0 && op%2==0)
      return cp/2+op/2;
    else 
      return (cp-1)/2 + (op-1)/2 +2;
}