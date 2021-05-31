/*
GeekforGeeks - Alien Dictionary 
ques:-
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
 

Example 1:

Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Example 2:

Input: 
N = 3, K = 3
dict = {"caa","aaa","aab"}
Output:
1
Explanation:
Here order of characters is
'c', 'a', 'b' Note that words are sorted
and in the given language "caa" comes before
"aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function findOrder() which takes  the string array dict[], its size N and the integer K as input parameter and returns a string denoting the order of characters in the alien language.


Expected Time Complexity: O(N + K)
Expected Space Compelxity: O(K)
*/

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        unordered_map<char, vector<char>> graph;
        for (int i = 1; i < N; i++)
        {
            string word1 = dict[i - 1];
            string word2 = dict[i];
            int j = 0;
            while (j < word1.length() && j < word2.length())
            {
                if (word1[j] != word2[j])
                    break;

                j++;
            }
            graph[word1[j]].push_back(word2[j]);
        }

        unordered_map<char, int> indegree;
        for (auto it : graph)
        {
            if (indegree.find(it.first) == indegree.end())
                indegree[it.first] = 0;
            for (auto c : it.second)
                indegree[c]++;
        }

        queue<char> pending;
        string output = "";

        for (auto it : indegree)
        {
            if (it.second == 0)
                pending.push(it.first);
        }

        while (!pending.empty())
        {
            char curr = pending.front();
            pending.pop();
            output += curr;
            for (int i = 0; i < graph[curr].size(); i++)
            {
                indegree[graph[curr][i]]--;
                if (indegree[graph[curr][i]] == 0)
                    pending.push(graph[curr][i]);
            }
        }

        return output;
    }
};