/*
pepcoding
1. You are given a number n.
2. You have to count the number of set bits in the given number.
Input Format
A number n
Output Format
Number of set bits in n
Constraints
1 <= n <= 10^9
Sample Input
58
Sample Output
4
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    while (n > 0)
    {
        n = n - (n & (-n));
        count++;
    }
    cout << count << endl;
}