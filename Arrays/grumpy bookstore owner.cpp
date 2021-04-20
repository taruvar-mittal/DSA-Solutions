/*
Leetcode 1052 - grumy bookstore owner
ques:- 
Today, the bookstore owner has a store open for customers.length minutes.  Every minute, some number of customers (customers[i]) enter the store, and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy.  If the bookstore owner is grumpy on the i-th minute, grumpy[i] = 1, otherwise grumpy[i] = 0.  When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for X minutes straight, but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.

 

Example 1:

Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
Output: 16
Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
*/

/* The idea is to find the normal satisfied customers and the maximum of extra number of customers that can be satisfied in window size of X */

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int normal = 0;
        for(int i=0;i<n;i++){
            normal+=(!grumpy[i] * customers[i]);
        }
        int currsum = 0;
        int i=0;
        for(;i<X;i++){
            currsum+=(grumpy[i]*customers[i]);
        }
        int maxsum = currsum;
        while(i<n){
            currsum+=(grumpy[i]*customers[i]);
            currsum-=(grumpy[i-X]*customers[i-X]);
            maxsum = max(maxsum,currsum);
            i++;
        }
        return normal+maxsum;
    }
};
