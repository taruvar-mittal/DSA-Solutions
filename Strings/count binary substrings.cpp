/*
Leetcode 696 - count binary substrings
ques:-
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.length();
        if(n<2)
            return 0;
        vector<int> count;
        char curr = s[0];
        int currcount = 1;
        for(int i=1;i<n;i++){
            if(s[i] == curr){
                currcount++;
            }else{
                count.push_back(currcount);
                curr = s[i];
                currcount = 1;
            }
        }
        count.push_back(currcount);
        int output = 0;
        for(int i=1;i<count.size();i++){
            output+=min(count[i],count[i-1]);
        }
        return output;
    }
};
