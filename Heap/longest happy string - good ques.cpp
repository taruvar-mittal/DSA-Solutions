/*
Leetcode 1405. Longest Happy String
ques:-
A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.

Given three integers a, b and c, return any string s, which satisfies following conditions:

s is happy and longest possible.
s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
s will only contain 'a', 'b' and 'c' letters.
If there is no such string s return the empty string "".

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 2, b = 2, c = 1
Output: "aabbc"
Example 3:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
*/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,string>> pq;
        if(a>0) pq.push({a,"a"});
        if(b>0) pq.push({b,"b"});
        if(c>0) pq.push({c,"c"});
        string output = "";
        
        while(!pq.empty()){
            pair<int,string> curr = pq.top();
            pq.pop();
            
            for(int i=0;i<min(2,curr.first);i++)
                output+=curr.second;
            curr.first-=2;
            
            if(pq.empty()) break;
            
            pair<int,string> next = pq.top();
            pq.pop();
            
            if(next.first>curr.first){
                    output+=next.second;
                   next.first--;
            }
        
            
            if(next.first>0) {
                output+=next.second;  
                next.first--;
        }
            
            if(curr.first>0) pq.push(curr);
            if(next.first>0) pq.push(next);
    }
        
        return output;
    }
};