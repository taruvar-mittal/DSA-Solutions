/* 
GeeksforGeeks - subarray with given sum
ques:- Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
*/

vector<int> subarraySum(int nums[], int n, int s){
    vector<int> output;

    if(n==0)
    return output;
    
    if(n==1 && s==nums[0]){
        output.push_back(1);
        output.push_back(1);
        return output;
    } else if(n==1 && s!=nums[0]){
        output.push_back(-1);
        return output;
    }
    
     int curr_sum = nums[0], start = 0, i; 
  
    for (i = 1; i <= n; i++) { 
        
        while (curr_sum > s && start < i - 1) { 
            curr_sum = curr_sum - nums[start]; 
            start++; 
        } 
  
        if (curr_sum == s) { 
            output.push_back(start+1);
            output.push_back(i);
            return output;
        } 
 
       curr_sum = curr_sum + nums[i];
    }
    output.push_back(-1);
    return output;
}
