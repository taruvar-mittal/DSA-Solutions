/*
Leetcode 402 - Remove K digits
ques:-
Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() || k==0 || num[st.top()]<num[i])
                st.push(i);
            else{
                while(!st.empty() && k>0 && num[st.top()]>num[i]){
                    st.pop();
                    k--;
                }
                st.push(i);
            }
        }
        // to handle case like "1234567"
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        string output = "";
        while(!st.empty()){
            output+=num[st.top()];
            st.pop();
        }
        reverse(output.begin(),output.end());
        int startzero = 0;
        while(output[startzero]=='0')
            startzero++;
        if(output.substr(startzero)=="")
            return "0";
        else
            return output.substr(startzero);
    }
};
