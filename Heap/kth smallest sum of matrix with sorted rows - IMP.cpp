/*
Leetcode 1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
ques:-
You are given an m * n matrix, mat, and an integer k, which has its rows sorted in non-decreasing order.

You are allowed to choose exactly 1 element from each row to form an array. Return the Kth smallest array sum among all possible arrays.

 

Example 1:

Input: mat = [[1,3,11],[2,4,6]], k = 5
Output: 7
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  
Example 2:

Input: mat = [[1,3,11],[2,4,6]], k = 9
Output: 17
Example 3:

Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
Output: 9
Explanation: Choosing one element from each row, the first k smallest sum are:
[1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3]. Where the 7th sum is 9.  
Example 4:

Input: mat = [[1,1,10],[2,2,9]], k = 7
Output: 12
*/

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        set<vector<int>> visited;
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
        int m = mat.size();
        int n = mat[0].size();

        int sum = 0;
        vector<int> v;
        for (int i = 0; i < m; i++)
        {
            sum += mat[i][0];
            v.push_back(0);
        }
        pq.push({sum, v});
        visited.insert(v);

        int count = 0;
        while (!pq.empty())
        {
            pair<int, vector<int>> curr = pq.top();
            pq.pop();
            int currsum = curr.first;
            vector<int> currv = curr.second;
            count++;

            if (count == k)
                return currsum;

            for (int i = 0; i < m; i++)
            {
                int x = i;
                int y = currv[i];
                if (y + 1 < n)
                {
                    currv[i]++;
                    if (!visited.count(currv))
                    {
                        pq.push({currsum - mat[i][y] + mat[i][y + 1], currv});
                        visited.insert(currv);
                    }
                    currv[i]--;
                }
            }
        }

        return -1;
    }
};