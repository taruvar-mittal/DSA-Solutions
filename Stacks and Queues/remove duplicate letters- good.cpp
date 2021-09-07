/* leetcode 316. Remove Duplicate Letters
ques:-
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"
*/

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> st;
        unordered_map<char, int> freq;

        vector<bool> visited(26, false);

        for (auto c : s)
        {
            freq[c]++;
        }

        for (auto c : s)
        {
            if (visited[c - 'a'])
            {
                freq[c]--;
                continue;
            }

            while (!st.empty() && st.top() > c && freq[st.top()] >= 1)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            freq[c]--;
            visited[c - 'a'] = true;
        }

        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};