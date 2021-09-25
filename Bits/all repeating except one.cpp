/*
pepcodingAll repeating except one
ques-
1. You are given an array of numbers.
2. All numbers occur twice in the array except one.
3. You have to find that number by traversing only once in the array and without using any extra 
     space.
Input Format
A number n
a1
a2..
n numbers
Output Format
Non-repeating number
Constraints
1 <= n <= 10^9
1 <= a1,a2.. <= 10^9 
Sample Input
5
23 27 23 17 17
Sample Output
27
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int output = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        output = output ^ x;
    }
    cout << output << endl;
}