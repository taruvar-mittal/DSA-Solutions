/*
GeeksforGeeks - Maximum difference between right and left smaller - variation of next smaller on right
ques:-
Given array A[] of integers, the task is to complete the function findMaxDiff which finds the maximum absolute difference between nearest left and right smaller element of every element in array.If the element is the leftmost element, nearest smaller element on left side is considered as 0. Similarly if the element is the rightmost elements, smaller element on right side is considered as 0.

Examples:

Input : arr[] = {2, 1, 8}
Output : 1
Left smaller  LS[] {0, 0, 1}
Right smaller RS[] {1, 0, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 1 

Input  : arr[] = {2, 4, 8, 7, 7, 9, 3}
Output : 4
Left smaller   LS[] = {0, 2, 4, 4, 4, 7, 2}
Right smaller  RS[] = {0, 3, 7, 3, 3, 3, 0}
Maximum Diff of abs(LS[i] - RS[i]) = 7 - 3 = 4 

Input : arr[] = {5, 1, 9, 2, 5, 1, 7}
Output : 1
*/

class Solution{
    public:

    int findMaxDiff(int A[], int n)
    {
        vector<int> leftsmaller(n,-1);
        vector<int> rightsmaller(n,-1);
        
        stack<int> st;
        for(int i=0;i<n;i++){
            if(st.empty()||A[i]>A[st.top()])
              st.push(i);
            else{
                while(!st.empty() && A[i]<A[st.top()]){
                     rightsmaller[st.top()] = i;
                    int temp = st.top();
                    st.pop();
                    // left smaller element is just the one below it in the stack
                    if(!st.empty())
                      leftsmaller[temp] = st.top();
                }
                st.push(i);
            }  
        }
        while(st.size()>1){
           int temp = st.top();
           st.pop();
           leftsmaller[temp] = st.top();
        }
        int maxdiff = INT_MIN;
        for(int i=0;i<n;i++){
        if(leftsmaller[i] == -1 && rightsmaller[i] == -1)
            maxdiff = max(maxdiff,0);
        else if(leftsmaller[i] == -1)
          maxdiff = max(maxdiff,A[rightsmaller[i]]);
        else if(rightsmaller[i] == -1)
          maxdiff = max(maxdiff,A[leftsmaller[i]]);
        else 
          maxdiff = max(maxdiff,abs(A[leftsmaller[i]] - A[rightsmaller[i]]));
    
        }
        return maxdiff;
    }
};
