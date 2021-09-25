/*
pepcoding 
print RSB value of number
1. You are given a number n.
2. You have to print the right-most set bit mask.
Input Format
A number n
Output Format
A number
Constraints
1 <= n <= 10^9
Sample Input
58
Sample Output
10
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n = (n & (-n));

    string output = "";

    while (n > 0)
    {
        output += to_string(n % 2);
        n /= 2;
    }

    reverse(output.begin(), output.end());
    cout << output << endl;
}