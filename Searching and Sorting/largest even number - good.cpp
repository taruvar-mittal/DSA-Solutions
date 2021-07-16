/*
gfgf largest even number 
ques:-
Given an integer S. Find the largest even number that can be formed by rearranging the digits of S.

Note: In case the number does not contain any even digit then output the largest odd number possible.

Example 1:

Input:
S = "1324"
Output: "4312"
Explanation: Largest even number: 4312
Example 2:

Input:
S = "3555"
Output: "5553"
Explanation: No even number possible,
So we'll find largest odd number.
*/

class Solution
{
public:
    string LargestEven(string S)
    {
        sort(S.begin(), S.end(), greater<char>());
        int n = S.length();
        if ((S[n - 1] - '0') % 2 == 0)
            return S;
        else
        {
            int i = n - 1;
            while (i >= 0 && (S[i] - '0') % 2 != 0)
                i--;
            if (i < 0)
                return S;
            else
            {
                char c = S[i];
                S.erase(i, 1);
                S = S + c;
            }
        }
        return S;
    }
};