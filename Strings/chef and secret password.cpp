/*
chef and secret password
ques:-
Chef wants to prepare a special dish. There is a special ingredient Chef needs for this dish, so he decided to search for it in all of Chefland. After some research, he discovered it in a secret cave. He may only enter the cave if he has a password; fortunately, a string S, which serves as a hint for this password, is written next to the cave.

Chef knows that the secret password is a non-empty prefix of the string S. Also, he knows that:

if a prefix occurs in S more often as a substring, then the probability that this prefix is the secret password is higher (the probability that a chosen prefix is the secret password is an increasing function of its number of occurrences in S)
if two prefixes have the same number of occurrences in S, then the longer prefix has a higher probability of being the secret password
Chef wants to guess the secret password with the maximum possible probability of success. Help Chef and find the prefix for which this probability is maximum.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains a single string S with length N.
Output
For each test case, print a single line containing one string — the prefix with the highest probability of being the secret password.

Constraints
1≤T≤100
1≤N≤100,000
S contains only lowercase English letters
Example Input
3
3
abc
5
thyth
5
abcbc
Example Output
abc
th
abcbc
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    string s;
	    cin>>s;
	    
	    unordered_map<ll,ll> mp;
	    
	    ll max_freq = 0;
	    ll len = -1;
	    
	    vector<ll> z(n,0);
	    
	    ll l=0,r=0;
	    
	    for(ll i=1;i<n;i++){
	        if(i<=r){
	            z[i] = min(i-l,r-i+1);
	        }
	        
	        while((i+z[i])<n && s[i+z[i]]==s[z[i]])
	          z[i]++;
	          
	        if(i+z[i]-1<r){
	            l = i;
	            r=  i+z[i]-1;
	        }
	        
	        if(z[i]!=0)
	          mp[z[i]]++;
	    }
	    
	    for(auto it:mp){
	        if(it.second>max_freq){
	            max_freq = it.second;
	            len = it.first;
	        }else if(it.second==max_freq){
	            len = max(len,it.first);
	        }
	    }
	    
	    if(len==-1) cout<<""<<endl;
	    else
	      cout<<s.substr(0,len)<<endl;
	}
	return 0;
}
