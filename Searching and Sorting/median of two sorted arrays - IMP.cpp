/*
Leetcode 4. Median of Two Sorted Arrays
ques:-
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000
Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000
Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
*/

class Solution
{
public:
    double mediann(vector<int> &a, vector<int> &b)
    {
        int m = a.size();
        int n = b.size();
        if (m > n)
            return mediann(b, a);
        int l = 0, r = m;
        while (l <= r)
        {
            int partx = l + (r - l) / 2;
            int party = (m + n + 1) / 2 - partx;
            int maxlx = (partx == 0) ? INT_MIN : a[partx - 1];
            int minrx = (partx == m) ? INT_MAX : a[partx];
            int maxly = (party == 0) ? INT_MIN : b[party - 1];
            int minry = (party == n) ? INT_MAX : b[party];
            if (maxlx <= minry && maxly <= minrx)
            {
                if ((m + n) % 2 == 0)
                    return (double)(max(maxlx, maxly) + min(minrx, minry)) / 2;
                else
                    return (double)(max(maxlx, maxly));
            }
            else if (maxlx > minry)
                r = partx - 1;
            else
                l = partx + 1;
        }
        return -1.0;
    }
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double ans;
        ans = mediann(nums1, nums2);
        return ans;
    }
};

// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();

//         if(m>n){
//             vector<int> temp = nums1;
//             nums1 = nums2;
//             nums2 = temp;
//         }

//         int totallength = m+n;
//         int half = (m+n+1)/2;
//         int start = 0;
//         int end = m;

//         while(start<=end){
//             int mid1 = (start+end)/2;
//             int mid2 = half-mid1;

//             int leftmax1 = getMax(nums1,mid1);
//             int rightmin1 = getMin(nums1,mid1);

//             int leftmax2 = getMax(nums2,mid2);
//             int rightmin2 = getMin(nums2,mid2);

//             if(leftmax1<=rightmin2 && leftmax2<=rightmin1){
//                 if(totallength%2==0){
//                     return (double)(max(leftmax1,leftmax2)+min(rightmin1,rightmin2))/(double)2;
//                 }
//                 else return (double)max(leftmax1,leftmax2);
//             }

//             if(leftmax1>rightmin2){
//                 end = mid1-1;
//             }else
//                 start = mid1+1;
//         }

//         return 0;
//     }

//     int getMax(vector<int>& nums,int part){
//         if(part<=0 || part>nums.size())
//             return INT_MIN;
//         else return nums[part-1];
//     }

//     int getMin(vector<int>& nums,int part){
//         if(part<=-1 || part>=nums.size())
//             return INT_MAX;
//         else return nums[part];
//     }
// };