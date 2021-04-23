/*
Leetcode 984 - String without AAA or BBB
ques:-
Given two integers a and b, return any string s such that:

s has length a + b and contains exactly a 'a' letters, and exactly b 'b' letters,
The substring 'aaa' does not occur in s, and
The substring 'bbb' does not occur in s.
 
Example 1:

Input: a = 1, b = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:

Input: a = 4, b = 1
Output: "aabaa"
*/

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string output = "";
        
        while(a>0 && b>0){
            if(a>b){
                output = output+"aab";
                a--;
            }else if(b>a){
                output = output + "bba";
                b--;
            }else{
                output = output + "ab";
            }
            a--;
            b--;
        }
        
        while(a>0){
            output = output + "a";
            a--;
        }
        while(b>0){
            output = output + "b";
            b--;
        }
        
        return output;
    }
};
