/*
shortest pallindrome - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/text-processing/shortest-palindrome-official/ojquestion#!
ques:-
1. You are given string(str). 
2. You can convert the given string to a palindrome by adding some characters in front of it.
3. You have to find the shortest palindromic string formed after performing the above-mentioned transformation.
Input Format
A string
Output Format
A string
Sample Input
coding
Sample Output
gnidocoding
*/

#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    string t = s;
    reverse(s.begin(), s.end());

    string temp = t + "#" + s;

    // cout<<temp<<endl;

    int n = temp.length();

    int i = 1, j = n - 1;

    int len = 0;

    while (i < j)
    {
        string s1 = temp.substr(0, i);
        string s2 = temp.substr(j);

        if (s1 == s2)
            len = i;

        i++;
        j--;
    }

    string a = t.substr(len);
    reverse(a.begin(), a.end());
    cout << a << t << endl;
}

int main()
{
    string str;
    cin >> str;

    solve(str);
}