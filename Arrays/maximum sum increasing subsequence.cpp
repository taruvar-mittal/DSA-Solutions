/* 
GeekforGeeks - Maximum Sum increasing Subsequence
ques:-
Given an array arr of N positive integers, the task is to find the maximum sum increasing subsequence of the given array.
 
Example 1:

Input: N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 106
Explanation:The maximum sum of a
increasing sequence is obtained from
{1, 2, 3, 100}
*/

class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int mis[n];
	    for(int i=0;i<n;i++){
	        mis[i] = arr[i];
	    }
	    
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i] && arr[i]+mis[j]>mis[i])
	              mis[i] = mis[j]+arr[i];
	        }
	    }
	    int ans = mis[0];
	    for(int i=1;i<n;i++){
	        ans = max(ans,mis[i]);
	    }
	    return ans;
	   
	}  
};

