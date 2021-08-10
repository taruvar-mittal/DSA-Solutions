/*
leetcode Add Strings
ques:-
Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

 

Example 1:

Input: num1 = "11", num2 = "123"
Output: "134"
Example 2:

Input: num1 = "456", num2 = "77"
Output: "533"
Example 3:

Input: num1 = "0", num2 = "0"
Output: "0"
*/

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string output = "";
        int m = num1.length() - 1;
        int n = num2.length() - 1;

        int carry = 0;
        int sum = 0;

        while (m >= 0 || n >= 0)
        {
            int a = 0, b = 0;
            if (m >= 0)
                a = num1[m--] - '0';
            if (n >= 0)
                b = num2[n--] - '0';

            sum = a + b + carry;
            carry = sum / 10;
            sum %= 10;

            output.push_back(sum + '0');
        }

        if (carry)
            output.push_back(carry + '0');

        reverse(output.begin(), output.end());
        return output;
    }
};