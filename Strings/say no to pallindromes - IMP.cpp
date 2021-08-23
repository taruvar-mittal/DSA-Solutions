/*
codeforces - https://codeforces.com/problemset/problem/1555/D
ques:- Say no to pallindromes
Let's call the string beautiful if it does not contain a substring of length at least 2, which is a palindrome. Recall that a palindrome is a string that reads the same way from the first character to the last and from the last character to the first. For example, the strings a, bab, acca, bcabcbacb are palindromes, but the strings ab, abbbaa, cccb are not.

Let's define cost of a string as the minimum number of operations so that the string becomes beautiful, if in one operation it is allowed to change any character of the string to one of the first 3 letters of the Latin alphabet (in lowercase).

You are given a string s of length n, each character of the string is one of the first 3 letters of the Latin alphabet (in lowercase).

You have to answer m queries — calculate the cost of the substring of the string s from li-th to ri-th position, inclusive.

Input
The first line contains two integers n and m (1≤n,m≤2⋅105) — the length of the string s and the number of queries.

The second line contains the string s, it consists of n characters, each character one of the first 3 Latin letters.

The following m lines contain two integers li and ri (1≤li≤ri≤n) — parameters of the i-th query.

Output
For each query, print a single integer — the cost of the substring of the string s from li-th to ri-th position, inclusive.

Example
inputCopy
5 4
baacb
1 3
1 5
4 5
2 3
outputCopy
1
2
0
1
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,m;
    cin>>n>>m;
    
    string s;
    cin>>s;
    
    vector<string> combos = {"abc","acb","bac","bca","cba","cab"};
    
    vector<vector<ll>> dp(6, vector<ll>(n+1,0));
    
    for(ll i=0;i<6;i++){
        string t = combos[i];
        for(ll j=1;j<=n;j++){
            if(s[j-1] == t[(j-1)%3])
              dp[i][j] = dp[i][j-1];
            else 
              dp[i][j] = dp[i][j-1]+1;
        }
    }
    
    // for(int i=0;i<6;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<dp[i][j];
    //     }
    //     cout<<endl;
    // }
    
    while(m--){
        ll l,r;
        cin>>l>>r;
        ll ans = INT_MAX;
        for(ll j=0;j<6;j++){
            ans = min(ans,dp[j][r]-dp[j][l-1]);
        }
        cout<<ans<<endl;
    }
}
