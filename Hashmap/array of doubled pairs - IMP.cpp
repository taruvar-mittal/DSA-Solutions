/*
Leetcode 954. Array of Doubled Pairs
ques:-
Given an array of integers arr of even length, return true if and only if it is possible to reorder it such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2.

 

Example 1:

Input: arr = [3,1,3,6]
Output: false
Example 2:

Input: arr = [2,1,2,6]
Output: false
Example 3:

Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
Example 4:

Input: arr = [1,2,4,16,8,4]
Output: false
*/

class Solution
{
public:
    bool canReorderDoubled(vector<int> &arr)
    {
        int n = arr.size();
        if (n % 2 != 0)
            return false;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                if (mp[arr[i]] > 0)
                {

                    if (arr[i] % 2 != 0)
                        return false;

                    if (mp[arr[i] / 2] > 0)
                    {
                        mp[arr[i]]--;
                        mp[arr[i] / 2]--;
                    }
                    else
                        return false;
                }
            }
            else
            {
                if (mp[arr[i]] > 0)
                {

                    if (mp[arr[i] * 2] > 0)
                    {
                        mp[arr[i]]--;
                        mp[arr[i] * 2]--;
                    }
                    else
                        return false;
                }
            }
        }
        return true;
    }
};