/*
Leetcode 85 - Maximal Rectangle
ques:-
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0
*/

class Solution {
public:
    int findHistogramArea(vector<int>& heights){
        int n = heights.size();
        vector<int> nser(n,n);
        vector<int> nsel(n,-1);
        
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty() || heights[i]>heights[st.top()])
                st.push(i);
            else{
                while(!st.empty() && heights[i]<heights[st.top()]){
                    nser[st.top()] = i;
                    int temp = st.top();
                    st.pop();
                    if(!st.empty())
                        nsel[temp] = st.top();
                }
                st.push(i);
            }
        }
        
        while(st.size()>1){
            int temp = st.top();
            st.pop();
            nsel[temp] = st.top();
        }
        
        int maxarea = INT_MIN;
        for(int i=0;i<n;i++){
            maxarea = max(maxarea,heights[i]*(nser[i]-nsel[i]-1));
        }
        return maxarea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0)
            return 0;
        int m = matrix[0].size();
        vector<int> myhistogram(m);
        for(int i=0;i<m;i++){
            myhistogram[i] = matrix[0][i]-'0';
        }
        
        int maxarea = findHistogramArea(myhistogram);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    myhistogram[j]++;
                }else{
                    myhistogram[j] = 0;
                }
            }
            maxarea = max(maxarea,findHistogramArea(myhistogram));
        }
        return maxarea;
    }
};
