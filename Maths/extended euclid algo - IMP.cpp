/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1045

ques:-
From Euclid it is known that for any positive integers A and B there exist such integers X and Y that
AX + BY = D, where D is the greatest common divisor of A and B. The problem is to find for given
A and B corresponding X, Y and D.
Input
The input will consist of a set of lines with the integer numbers A and B, separated with space
(A, B < 1000000001).
Output
For each input line the output line should consist of three integers X, Y and D, separated with space.
If there are several such X and Y , you should output that pair for which |X| + |Y | is the minimal. If
there are several X and Y satisfying the minimal criteria, output the pair for which X ≤ Y .
Sample Input
4 6
17 17
Sample Output
-1 1 2
0 1 17
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, pair<int, int>> eea(int a, int b)
{
    if (b == 0)
    {
        return {a, {1, 0}};
    }

    pair<int, pair<int, int>> dash = eea(b, a % b);

    return {dash.first, {dash.second.second, dash.second.first - (a / b) * dash.second.second}};
}

int main()
{
    int a;
    int b;
    cin >> a;
    cin >> b;

    pair<int, pair<int, int>> ans = eea(a, b);
    cout << ans.second.first << " " << ans.second.second << " " << ans.first << endl;
    return 0;
}
