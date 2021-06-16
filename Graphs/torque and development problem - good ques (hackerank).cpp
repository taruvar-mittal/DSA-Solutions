/*
Hackerank - https://www.hackerrank.com/challenges/torque-and-development/problem

ques:- Roads and libraries
*/

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int vertex, int c_road, long &output)
{
    for (int i = 0; i < graph[vertex].size(); i++)
    {
        if (!visited[graph[vertex][i]])
        {
            visited[graph[vertex][i]] = true;
            output += c_road;
            dfs(graph, visited, graph[vertex][i], c_road, output);
        }
    }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
    if (c_lib <= c_road)
    {
        return (long)n * c_lib;
    }

    vector<vector<int>> graph(n, vector<int>());
    for (auto v : cities)
    {
        graph[v[0] - 1].push_back(v[1] - 1);
        graph[v[1] - 1].push_back(v[0] - 1);
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({graph[i].size(), i});
    }

    vector<bool> visited(n, false);
    long output = 0;

    while (!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();
        if (visited[curr.second])
            continue;
        else
        {
            output += c_lib;
            visited[curr.second] = true;
            dfs(graph, visited, curr.second, c_road, output);
        }
    }
    return output;
}
