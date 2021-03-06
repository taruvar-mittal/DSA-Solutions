/*
Leetcode 503 - Next Greater Element Circular

ques:-
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n,-1);
        
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()|| nums[i]<=nums[st.top()]){
                st.push(i);
            }else{
                while(!st.empty() && nums[i]>nums[st.top()]){
                    output[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i]>nums[st.top()]){
                output[st.top()] = nums[i];
                st.pop();
            }
        }
        return output;
    }
};


// another approach - not good
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        if(arr.size()==0) return {};
        
        vector<int> nums = arr;
        nums.insert(nums.end(), arr.begin(),arr.end());
        
        vector<int> output(nums.size());
        stack<int> st;
        
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                output[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            output[st.top()] = -1;
            st.pop();
        }
        
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            res.push_back(output[i]);
        }
        return res;
    }
};
