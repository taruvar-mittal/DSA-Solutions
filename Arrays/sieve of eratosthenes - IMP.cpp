/*
ques:-
Given a number N, calculate the prime numbers up to N using Sieve of Eratosthenes.  

Example 1:

Input:
N = 10

Output:
2 3 5 7

Explanation:
Prime numbers less than equal to N 
are 2 3 5 and 7.
Example 2:

Input:
N = 35

Output:
2 3 5 7 11 13 17 19 23 29 31

Explanation:
Prime numbers less than equal to 35 are
2 3 5 7 11 13 17 19 23 29 and 31.
*/

class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        vector<bool> arr(N + 1);

        for (int i = 2; i * i <= N; i++)
        {
            if (arr[i] == false)
            {
                for (int j = i * 2; j <= N; j += i)
                    arr[j] = true;
            }
        }

        vector<int> output;
        for (int i = 2; i <= N; i++)
        {
            if (arr[i] == false)
                output.push_back(i);
        }

        return output;
    }
};