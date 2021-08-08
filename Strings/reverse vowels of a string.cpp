/*
leetcode 345. Reverse Vowels of a String
ques:-
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
*/

class Solution {
public:
    bool isVowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
    }
    
    string reverseVowels(string s) {
        int n = s.length();
        int i=0;
        int j=n-1;
        
        while(i<j){
            while(i<j && !isVowel(s[i]))
                i++;
            while(i<j && !isVowel(s[j]))
                j--;
            
            if(i>=j) break;
            swap(s[i],s[j]);
            i++;
            j--;
                
        }
        return s;
    }
};