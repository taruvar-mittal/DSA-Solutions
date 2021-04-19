/*
Leetcode 918 - Maximum circular subarray sum
ques - 
Given a circular array C of integers represented by A, find the maximum possible sum of a non-empty subarray of C.

Here, a circular array means the end of the array connects to the beginning of the array.  (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

Also, a subarray may only include each element of the fixed buffer A at most once.  (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

 

Example 1:

Input: [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3
Example 2:

Input: [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10
Example 3:

Input: [3,-1,2,-1]
Output: 4
Explanation: Subarray [2,-1,3] has maximum sum 2 + (-1) + 3 = 4
*/

class Solution {
public:
    int findKadane(vector<int> &A){
        int max_so_far = INT_MIN;
        int max_ending_here = 0;
        for(int i=0;i<A.size();i++){
            max_ending_here+=A[i];
            max_so_far = max(max_so_far,max_ending_here);
            if(max_ending_here<0)
                max_ending_here = 0;
        }
        return max_so_far;
    }
    
    int checkAllNegative(vector<int>&A){
        int ans = A[0];
        for(int i=1;i<A.size();i++){
            if(ans>=0)
                return ans;
            
            ans = max(ans,A[i]);
        }
        return ans;
    }
    
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        if(n==0)
            return 0;
        
        int largest = checkAllNegative(A);
        if(largest<0)
            return largest;
        
        int kadanesum = findKadane(A);
        
        int totalsum = 0;
        for(int i=0;i<n;i++){
            totalsum+=A[i];
            A[i] = -A[i];
        }
        
        int newkadane = findKadane(A);
        
        return max(kadanesum,totalsum+newkadane);
       
    }
};
