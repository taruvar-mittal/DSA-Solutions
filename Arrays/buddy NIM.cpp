/*
codechef Buddy NIM 
ques:-
Alice, Bob and Charlie are playing a new game called Buddy NIM. The game is played at two tables; on the first table, there are N heaps containing A1,A2,…,AN stones and on the second table, there are M heaps containing B1,B2,…,BM stones respectively.

Initially, Alice is playing at the first table and Bob is playing at the second table. The players take their turns in this order: Charlie, Alice, Bob, Charlie, etc.

Alice and Bob follow the rules for classical NIM - on Alice's turn, Alice must remove a positive number of stones from one of the piles at her current table and on Bob's turn, Bob must remove a positive number of stones from one of the piles at his current table. Whoever cannot remove any stone from a pile loses.

Charlie does not play at any table. Instead, on his turn, he decides if Alice and Bob should keep playing at their respective tables or swap places.

Alice and Charlie are buddies and they cooperate, playing in the optimal way that results in Alice's victory (if possible).

It is clear that either Alice or Bob wins the game eventually. You must find out who the winner will be.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each testcase contains two space-separated integers N and M.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains M space-separated integers B1,B2,…,BM.
Output
Print a single line containing the string "Alice" if Alice wins or "Bob" if Bob wins.

Constraints
1≤T≤102
1≤N,M≤102
0≤Ai≤109 for each valid i
0≤Bi≤109 for each valid i
Example Input
3
3 1
1 1 1
3
3 1
1 2 4
7
1 1
1
1
Example Output
Alice
Alice
Bob
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
        ll n, m;
        cin >> n >> m;
        vector<ll> alice;
        vector<ll> bob;

        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x == 0)
                continue;
            alice.push_back(x);
        }

        for (ll j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            if (x == 0)
                continue;
            bob.push_back(x);
        }

        sort(alice.begin(), alice.end());
        sort(bob.begin(), bob.end());

        if (alice == bob)
            cout << "Bob" << endl;
        else
            cout << "Alice" << endl;
    }
    return 0;
}
