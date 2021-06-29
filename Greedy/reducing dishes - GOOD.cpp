/*
Leetcode 1402. Reducing Dishes
ques:-
A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.

Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level  i.e.  time[i]*satisfaction[i]

Return the maximum sum of Like-time coefficient that the chef can obtain after dishes preparation.

Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.

 

Example 1:

Input: satisfaction = [-1,-8,0,5,-9]
Output: 14
Explanation: After Removing the second and last dish, the maximum total Like-time coefficient will be equal to (-1*1 + 0*2 + 5*3 = 14). Each dish is prepared in one unit of time.
Example 2:

Input: satisfaction = [4,3,2]
Output: 20
Explanation: Dishes can be prepared in any order, (2*1 + 3*2 + 4*3 = 20)
Example 3:

Input: satisfaction = [-1,-4,-5]
Output: 0
Explanation: People don't like the dishes. No dish is prepared.
Example 4:

Input: satisfaction = [-2,5,-1,0,3,-3]
Output: 35
*/

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        vector<int> neg;
        vector<int> pos;

        for (auto x : satisfaction)
        {
            if (x < 0)
                neg.push_back(x);
            else
                pos.push_back(x);
        }

        if (pos.size() == 0)
            return 0;

        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());

        int output = 0;
        for (int i = 1; i <= pos.size(); i++)
        {
            output += pos[i - 1] * i;
        }

        for (int i = neg.size() - 1; i >= 0; i--)
        {
            int curr = 0;
            int factor = 1;
            for (int j = i; j < neg.size(); j++)
            {
                curr += neg[j] * factor;
                factor++;
            }

            for (int j = 1; j <= pos.size(); j++)
            {
                curr += pos[j - 1] * factor;
                factor++;
            }

            cout << curr << endl;

            output = max(output, curr);
        }

        return output;
    }
};