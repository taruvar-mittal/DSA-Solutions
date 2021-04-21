/*
Leetcode 763 - Partition Labels
ques:-
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.length();
        
        unordered_map<char,int> indexes;
        for(int i=0;i<S.length();i++){
            indexes[S[i]] = i;
        }
        
        vector<int> output;
      
        for(int i=0;i<S.length();i++){
            int start = i;
            int end = indexes[S[i]];
            
            while(i<n && i<end){
                end = max(end,indexes[S[i]]);
                i++;
            }
            
            output.push_back(end-start+1);
        }
        return output;
    }
};
