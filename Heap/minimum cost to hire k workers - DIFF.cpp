/*
Leetcode 857. Minimum Cost to Hire K Workers
ques:-
There are n workers.  The i-th worker has a quality[i] and a minimum wage expectation wage[i].

Now we want to hire exactly k workers to form a paid group.  When hiring a group of k workers, we must pay them according to the following rules:

Every worker in the paid group should be paid in the ratio of their quality compared to other workers in the paid group.
Every worker in the paid group must be paid at least their minimum wage expectation.
Return the least amount of money needed to form a paid group satisfying the above conditions.

 

Example 1:

Input: quality = [10,20,5], wage = [70,50,30], k = 2
Output: 105.00000
Explanation: We pay 70 to 0-th worker and 35 to 2-th worker.
Example 2:

Input: quality = [3,1,10,10,1], wage = [4,8,2,2,7], k = 3
Output: 30.66667
Explanation: We pay 4 to 0-th worker, 13.33333 to 2-th and 3-th workers seperately. 
*/

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();
        vector<vector<double>> v(n, vector<double>());

        for (int i = 0; i < n; i++)
        {
            v[i] = {(double)wage[i] / (double)quality[i], (double)quality[i]};
        }

        sort(v.begin(), v.end());

        double output = DBL_MAX;
        double sum = 0;

        priority_queue<double> pq;

        for (int i = 0; i < n; i++)
        {
            sum += v[i][1];
            pq.push(v[i][1]);

            while (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k)
                output = min(output, sum * v[i][0]);
        }
        return output;
    }
};