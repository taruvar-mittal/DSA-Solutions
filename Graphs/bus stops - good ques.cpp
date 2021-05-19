/*
Leetcode 815. Bus Routes
ques:-
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.
Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
*/

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target || routes.size() == 0)
            return 0;

        int n = routes.size();
        unordered_map<int, vector<int>> busStops;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < routes[i].size(); j++)
            {
                busStops[routes[i][j]].push_back(i);
            }
        }

        vector<bool> busVisited(n, false);
        unordered_map<int, bool> stopVisited;
        for (auto it = busStops.begin(); it != busStops.end(); it++)
        {
            stopVisited[it->first] = false;
        }

        queue<pair<int, int>> pendingNodes;
        pendingNodes.push({source, 0});
        stopVisited[source] = true;

        while (!pendingNodes.empty())
        {
            int size = pendingNodes.size();
            while (size--)
            {
                pair<int, int> curr = pendingNodes.front();
                pendingNodes.pop();
                if (curr.first == target)
                    return curr.second;

                vector<int> buses = busStops[curr.first];
                for (int i = 0; i < buses.size(); i++)
                {
                    if (busVisited[buses[i]] == true)
                        continue;

                    vector<int> stops = routes[buses[i]];
                    for (int j = 0; j < stops.size(); j++)
                    {
                        if (stopVisited[stops[j]] == true)
                            continue;
                        pendingNodes.push({stops[j], curr.second + 1});
                        stopVisited[stops[j]] = true;
                    }

                    busVisited[buses[i]] = true;
                }
            }
        }

        return -1;
    }
};