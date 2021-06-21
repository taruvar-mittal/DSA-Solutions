/*
codechef Mode of frequencies
Chef opted for Bio-Statistics as an Open-Elective course in his university, but soon got bored, and decided to text his friends during lectures. The instructor caught Chef, and decided to punish him, by giving him a special assignment.

There are N numbers in a list A=A1,A2,…,AN. Chef needs to find the mode of the frequencies of the numbers. If there are multiple modal values, report the smallest one. In other words, find the frequency of all the numbers, and then find the frequency which has the highest frequency. If multiple such frequencies exist, report the smallest (non-zero) one.

More formally, for every v such that there exists at least one i such that Ai=v, find the number of j such that Aj=v, and call that the frequency of v, denoted by freq(v). Then find the value w such that freq(v)=w for the most number of vs considered in the previous step. If there are multiple values w which satisfy this, output the smallest among them.

As you are one of Chef's friends, help him complete the assignment.

Input:
The first line contains an integer T, the number of test cases.
The first line of each test case contains an integer N, the number of values in Chef's assignment.
The second line of each test case contains N space-separated integers, Ai, denoting the values in Chef's assignment.
Output:
For each test case, print the mode of the frequencies of the numbers, in a new line.

Constraints
1≤T≤100
1≤N≤10000
1≤Ai≤10
Subtasks
30 points : 1≤N≤100
70 points : Original constraints.

Sample Input:
2
8
5 9 2 9 7 2 5 3
9
5 9 2 9 7 2 5 3 1

Sample Output:
2
1
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        unordered_map<ll, ll> freq;
        for (ll i = 0; i < n; i++)
        {
            ll num;
            cin >> num;
            freq[num]++;
        }
        unordered_map<ll, ll> freq2;
        for (auto it : freq)
        {
            freq2[it.second]++;
        }

        // for(auto it:freq2){
        //     cout<<it.first<<it.second<<endl;
        // }
        ll maxfreq = 0;
        ll output = -1;
        for (auto it : freq2)
        {
            if (it.second > maxfreq || (it.second == maxfreq && it.first < output))
            {
                maxfreq = it.second;
                output = it.first;
            }
        }
        cout << output << endl;
    }
    return 0;
}
