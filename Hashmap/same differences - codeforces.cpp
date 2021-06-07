/*
Codeforces
D. Same Differences
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of n integers. Count the number of pairs of indices (i,j) such that i<j and aj−ai=j−i.

Input
The first line contains one integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains one integer n (1≤n≤2⋅105).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — array a.

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case output the number of pairs of indices (i,j) such that i<j and aj−ai=j−i.

Example
input
4
6
3 5 1 4 6 6
3
1 2 3
4
1 3 3 4
6
1 6 3 4 5 6
output
1
3
3
10
*/

#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int> &arr)
{
    int n = arr.size();
    long long count = 0;
    unordered_map<int, int> mp;

    for (int j = 1; j <= n; j++)
    {
        int num = arr[j - 1] - j;
        if (mp.find(num) != mp.end())
            count += mp[num];
        mp[num]++;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}