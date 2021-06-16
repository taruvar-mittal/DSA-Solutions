/*
Hackerank https://www.hackerrank.com/challenges/even-tree/problem?isFullScreen=true
*/

#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int num, root;
};
int main()
{
    int N, M; //nodes edges
    int x, y;
    int count = 0;
    cin >> N >> M;

    vector<int> parent(N, -1);
    vector<int> size(N, 1);

    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        parent[x - 1] = y - 1;
    }

    for (int i = N - 1; i > 0; i--)
        if (parent[i] >= 0)
            size[parent[i]] += size[i];
    for (int i = 0; i < N; i++)
        if (parent[i] >= 0 && size[i] % 2 == 0)
            count++;

    cout << count;
    return 0;
}