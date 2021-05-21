/*
Leetcode 433. Minimum Genetic Mutation
ques:-
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

Example 1:

Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
Example 3:

Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
Output: 3
*/

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_map<char, vector<char>> swaps;
        swaps['A'] = {'C', 'G', 'T'};
        swaps['C'] = {'A', 'G', 'T'};
        swaps['G'] = {'A', 'C', 'T'};
        swaps['T'] = {'A', 'C', 'G'};

        int count = 0;
        queue<string> pendingNodes;
        pendingNodes.push(start);

        while (!pendingNodes.empty())
        {
            int size = pendingNodes.size();
            while (size--)
            {
                string curr = pendingNodes.front();
                pendingNodes.pop();
                if (curr == end)
                    return count;

                for (int i = 0; i < curr.size(); i++)
                {
                    char c = curr[i];
                    for (int j = 0; j < swaps[c].size(); j++)
                    {
                        curr[i] = swaps[c][j];
                        if (find(bank.begin(), bank.end(), curr) != bank.end())
                        {

                            //to mark the given string as visited we remove it from the bank
                            bank.erase(remove(bank.begin(), bank.end(), curr), bank.end());

                            pendingNodes.push(curr);
                        }
                    }
                    curr[i] = c;
                }
            }
            count++;
        }
        return -1;
    }
};