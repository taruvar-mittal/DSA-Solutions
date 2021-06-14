/*
Leetcode 1462. Course Schedule IV
ques:-
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether the course uj is a prerequisite of the course vj or not. Note that if course a is a prerequisite of course b and course b is a prerequisite of course c, then, course a is a prerequisite of course c.

Return a boolean array answer, where answer[j] is the answer of the jth query.

 

Example 1:


Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
Output: [false,true]
Explanation: course 0 is not a prerequisite of course 1 but the opposite is true.
Example 2:

Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
Output: [false,false]
Explanation: There are no prerequisites and each course is independent.
Example 3:


Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
Output: [true,true]
 
*/

class Solution
{
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        vector<vector<bool>> mat(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            mat[i][i] = true;
        }

        for (auto v : prerequisites)
        {
            mat[v[0]][v[1]] = true;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i == j || i == k || j == k)
                        continue;
                    mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
                }
            }
        }

        int q = queries.size();
        vector<bool> output(q, false);

        for (int i = 0; i < q; i++)
        {
            if (mat[queries[i][0]][queries[i][1]])
                output[i] = true;
        }
        return output;
    }
};