/*
Lintcode 861 · K Empty Slots
ques:-
Description
There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.

If there are multiple answers, choose the smallest.
If there isn't such day, output -1.

The given array will be in the range [1, 20000].
Example
Example 1:

Input：[1,2,3,4]，k=1
Output：-1
Explanation：The first two flowers to open are next to each other.
Example 2:

Input：[1,3,2]，k=1
Output：2
Explanation：In the second day, the first and the thir
*/

class Solution
{
public:
    int kEmptySlots(vector<int> &flowers, int k)
    {
        int n = flowers.size();
        vector<int> days(n);
        for (int i = 0; i < n; i++)
        {
            days[flowers[i] - 1] = i + 1;
        }
        int left = 0;
        int right = k + 1;
        int ans = INT_MAX;
        for (int i = 1; right < n; i++)
        {
            if (days[i] > days[left] && days[i] > days[right])
            {
                continue;
            }
            if (i == right)
            {
                ans = min(ans, max(days[left], days[right]));
            }
            left = i;
            right = left + k + 1;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};