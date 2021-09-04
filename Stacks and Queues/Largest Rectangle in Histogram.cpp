/*
Leetcode 84 - Largest Rectangle in Histogram
ques:-
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightsmaller(n,n);
        vector<int> leftsmaller(n,-1);
        
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()||heights[i]>heights[st.top()])
              st.push(i);
            else{
                while(!st.empty() && heights[i]<heights[st.top()]){
                     rightsmaller[st.top()] = i;
                    int temp = st.top();
                    st.pop();
                    if(!st.empty())
                      leftsmaller[temp] = st.top();
                }
                // to handle equal valued elements
                // if(!st.empty() && (heights[i] == heights[st.top()])){
                //     st.pop();
                // }
 
                  st.push(i);
            }  
        }
        while(st.size()>1){
           int temp = st.top();
           st.pop();
           leftsmaller[temp] = st.top();
        }
        
        int maxarea = INT_MIN;
        for(int i=0;i<n;i++){
            maxarea = max(maxarea,heights[i]*(rightsmaller[i] - leftsmaller[i] -1));
        }
       return maxarea;
    }
};


// another approach - better
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int omax = 0;
        for(int i=0;i<=heights.size();i++){
            int val = i==heights.size() ? 0 : heights[i];
            
            while(!st.empty() && heights[st.top()]>val){
                int h = st.top();
                st.pop();
                int nsl = st.empty() ? -1 : st.top();
                int nsr = i;
                int width = nsr-nsl-1;
                
                omax = max(omax,heights[h]*width);
            }
            st.push(i);
        }
        
        return omax;
    }
};