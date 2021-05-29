/*
GfG - JOB SEQUENCING
Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

Note: Jobs will be given in the form (Job id, Deadline, Profit) associated to that Job.

Example 1:

Input:
N = 4
Jobs = (1,4,20)(2,1,10)(3,1,40)(4,1,30)
Output:
2 60
Explanation:
2 jobs can be done with
maximum profit of 60 (20+40).
Example 2:

Input:
N = 5
Jobs = (1,2,100)(2,1,19)(3,2,27)
(4,1,25)(5,1,15)
Output:
2 127
Explanation:
2 jobs can be done with
maximum profit of 127 (100+27).
*/

class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        if (x == parent[x])
            return x;
        int temp = find(parent, parent[x]);
        parent[x] = temp;
        return temp;
    }

    void merge(vector<int> &parent, int x, int y)
    {
        int pox = find(parent, x);
        int poy = find(parent, y);

        if (pox == poy)
            return;

        parent[pox] = poy;
    }

    static bool comp(Job &a, Job &b)
    {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<int> parent(n + 1);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;

        sort(arr, arr + n, comp);

        int total = 0;
        int jobs = 0;

        for (int i = 0; i < n; i++)
        {
            int availableSlot = find(parent, arr[i].dead);

            if (availableSlot > 0)
            {
                merge(parent, availableSlot, availableSlot - 1);
                total += arr[i].profit;
                jobs++;
            }
        }

        return {jobs, total};
    }
};