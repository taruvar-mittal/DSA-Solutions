/*
Leetcode 997. Find the Town Judge
ques:-
In a town, there are n people labelled from 1 to n.  There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.

If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.


Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
Example 4:

Input: n = 3, trust = [[1,2],[2,3]]
Output: -1
Example 5:

Input: n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
Output: 3
*/

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> outdegree(n, 0);
        vector<int> indegree(n, 0);
        for (int i = 0; i < trust.size(); i++)
        {
            outdegree[trust[i][0] - 1]++;
            indegree[trust[i][1] - 1]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (outdegree[i] == 0 && indegree[i] == n - 1)
                return i + 1;
        }
        return -1;
    }
};