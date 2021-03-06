/*
Leetcode 791 - Custom Sort String
ques:-
S and T are strings composed of lowercase letters. In S, no letter occurs more than once.

S was sorted in some custom order previously. We want to permute the characters of T so that they match the order that S was sorted. More specifically, if x occurs before y in S, then x should occur before y in the returned string.

Return any permutation of T (as a string) that satisfies this property.

Example :
Input: 
S = "cba"
T = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in S, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in S, it can be at any position in T. "dcba", "cdba", "cbda" are also valid outputs.
*/

class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char,int> frequency;
        for(int i=0;i<T.length();i++){
            frequency[T[i]]++;
        }
        string output;
        for(int i=0;i<S.length();i++){
            while(frequency[S[i]]>0){
                output+=S[i];
                frequency[S[i]]--;
            }
        }
        for(auto it:frequency){
            while(it.second>0){
                output+=it.first;
                it.second--;
            }
        }
        return output;
    }
};
