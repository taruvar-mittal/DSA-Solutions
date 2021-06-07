/*
Leetcode 347. Top K Frequent Elements
ques:-
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (auto it : freq)
        {
            if (pq.size() < k)
            {
                pq.push({it.second, it.first});
            }
            else
            {
                if (pq.top().first < it.second)
                {
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }

        vector<int> output;
        while (!pq.empty())
        {
            output.push_back(pq.top().second);
            pq.pop();
        }
        return output;
    }
};
