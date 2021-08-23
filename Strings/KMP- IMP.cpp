/*
kmp https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/text-processing/kmp-pattern-searching-official/ojquestion
ques-
1. You are given two strings s1 and s2.
2. s1 represents a text and s2 represents a pattern. 
3. You have to print the starting index for all occurrences of the pattern in the given text string.
Input Format
Two strings s1 and s2 in two different lines.
Output Format
Starting index for all occurrences of the pattern in the given text string.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> helper(string s, string t)
{
    int m = s.length();
    int n = t.length();

    string temp = t + "#" + s;

    vector<int> lps(temp.length(), 0);
    vector<int> output;

    int i = 1, len = 0;

    // cout<<temp<<endl;

    while (i < temp.length())
    {
        if (temp[len] == temp[i])
        {
            len++;
            lps[i] = len;
            i++;

            // cout<<lps[i]<<endl;
        }
        else
        {
            if (len > 0)
            {
                len = lps[len - 1];
            }
            else
            {
                i++;
            }
        }
    }

    // for(int j=0;j<lps.size();j++){
    //     cout<<lps[i];
    // }

    for (int i = 0; i < lps.size(); i++)
    {
        if (lps[i] == n)
        {
            output.push_back(i - 2 * n);
        }
    }
    return output;
}

int main()
{
    string s, t;
    cin >> s >> t;

    vector<int> output = helper(s, t);

    if (output.size() == 0)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i] << endl;
        }
    }
}