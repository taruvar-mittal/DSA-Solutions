/*
GeeksforGeeks - First negative integer in k sized window
ques:-
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 
*/

vector<int> printFirstNegativeInteger(int arr[], int k, int n)
{
    vector<int> output;
    int lastnegindex = n;
    int i= n-1;
    for(int j=0;j<k;j++){
        if(arr[i]<0)
          lastnegindex = i;
        i--;
    }
    if(lastnegindex!=n)
      output.push_back(arr[lastnegindex]);
    else
      output.push_back(0);
      
      while(i>=0){
          if(arr[i]<0)
            lastnegindex = i;
          if(lastnegindex<=i+k-1)
            output.push_back(arr[lastnegindex]);
          else
            output.push_back(0);
            
            i--;
      }
      reverse(output.begin(),output.end());
      return output;
}
 
