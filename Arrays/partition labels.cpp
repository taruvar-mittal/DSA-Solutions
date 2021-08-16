/*
leetcode 763. Partition Labels
ques:-
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Return a list of integers representing the size of these parts.


Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
*/

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.length();
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i;
        }

        vector<int> output;

        int i = 0, j = 0;
        int partition = 0;

        while (j < n)
        {
            partition = max(partition, last[s[j] - 'a']);
            if (partition == j)
            {
                output.push_back(j - i + 1);
                i = j + 1;
            }
            j++;
        }

        return output;
    }
};