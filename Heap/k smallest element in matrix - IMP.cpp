/*
Leetcode 378. Kth Smallest Element in a Sorted Matrix
ques:-
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
*/

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        for (int i = 0; i < n; i++)
        {
            pq.push({matrix[i][0], {i, 0}});
        }
        int count = 0;
        while (!pq.empty())
        {
            pair<int, pair<int, int>> curr = pq.top();
            pq.pop();
            // cout<<curr.first<<curr.second.first<<curr.second.second<<endl;
            count++;
            if (count == k)
                return curr.first;
            int row = curr.second.first;
            int col = curr.second.second;
            if (col + 1 < n)
                pq.push({matrix[row][col + 1], {row, col + 1}});
        }

        return -1;
    }
};