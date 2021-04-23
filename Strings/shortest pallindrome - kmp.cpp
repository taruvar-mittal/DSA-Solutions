/*
Leetcode 214 - Shortest Pallindrome - KMP solution
ques:-
You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string temp = s;
        temp = temp+"#";
        string temp2 = s;
        reverse(temp2.begin(),temp2.end());
        temp = temp+temp2;
        
        int n = temp.length();
        int lps[n];
        int i=1;
        int len = 0;
        lps[0] = 0;
        while(i<n){
            if(temp[i] == temp[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len>0)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        int m = s.length();
        string temp3 = s.substr(lps[n-1],m-n+1);
        reverse(temp3.begin(),temp3.end());
        return temp3+s;
    }
};
