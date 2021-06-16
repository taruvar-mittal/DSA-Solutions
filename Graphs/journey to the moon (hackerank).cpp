/*
hackerank https://www.hackerrank.com/challenges/journey-to-the-moon/problem
*/

/* This code doesn't pass the last test case due to int32 overflow */

int find(vector<int> &parent, int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent, parent[x]);
}

void merge(vector<int> &parent, vector<int> &size, int x, int y)
{
    int pox = find(parent, x);
    int poy = find(parent, y);

    if (pox == poy)
        return;

    if (size[pox] > size[poy])
    {
        parent[pox] = poy;
        size[poy] += size[pox];
    }
    else
    {
        parent[poy] = pox;
        size[pox] += size[poy];
    }
}

int findsum(vector<int> &arr)
{
    int total = 0;
    int squaresum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        total += arr[i];
        squaresum += arr[i] * arr[i];
    }

    total = total * total;

    return (total - squaresum) / 2;
}

int journeyToMoon(int n, vector<vector<int>> astronaut)
{
    vector<int> parent(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    vector<int> size(n, 1);

    for (auto v : astronaut)
    {
        merge(parent, size, v[0], v[1]);
    }

    vector<int> distinct;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
            distinct.push_back(size[i]);
    }

    return findsum(distinct);
}