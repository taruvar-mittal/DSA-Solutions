/*
leetcode 43. Multiply Strings
ques:-
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
*/

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int m = num1.length();
        int n = num2.length();

        vector<int> ans(m + n, 0);

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int val = (num1[i] - '0') * (num2[j] - '0');

                int idx1 = i + j;
                int idx2 = i + j + 1;

                val += ans[idx2];
                int quo = val / 10;
                int carry = val % 10;

                ans[idx2] = carry;
                ans[idx1] += quo;
            }
        }

        string output = "";

        int i = 0;
        while (i < ans.size() && ans[i] == 0)
            i++;

        while (i < ans.size())
        {
            output.push_back(ans[i] + '0');
            i++;
        }

        if (output == "")
            return "0";
        else
            return output;
    }
};