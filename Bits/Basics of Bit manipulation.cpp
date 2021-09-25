/* pepcoding 
1. You are given a number n.
2. Print the number produced on setting its i-th bit.
3. Print the number produced on unsetting its j-th bit.
4. Print the number produced on toggling its k-th bit.
5. Also, Check if its m-th bit is on or off. Print 'true' if it is on, otherwise print 'false'.
Input Format
A number
Four numbers i,j,k,m.
Constraints
1 <= n <= 10^9
1 <= i <= 9
1 <= j <= 9
1 <= k <= 9
1 <= m <= 9
Sample Input
57
3 
3 
3 
3
Sample Output
57
49
49
true
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, j, k, m;
    cin >> n >> i >> j >> k >> m;

    int mask1 = (1 << i);
    int mask2 = (1 << j);
    int mask3 = (1 << k);
    int mask4 = (1 << m);

    cout << (n | mask1) << endl;
    cout << (n & ~mask2) << endl;
    cout << (n ^ mask3) << endl;
    cout << ((n & mask4) == 0 ? "false" : "true") << endl;
}