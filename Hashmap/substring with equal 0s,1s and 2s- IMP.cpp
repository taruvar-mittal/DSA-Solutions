/*
GeeksforGeeks  - Equal 0s, 1s and 2s
ques:-
Given a string str of length N which consists of only 0, 1 or 2s, count the number of substring which have equal number of 0s, 1s and 2s.
 

Example 1:

Input: str = “0102010”
Output: 2
Explanation: Substring str[2, 4] = “102” and
substring str[4, 6] = “201” has equal number
of 0, 1 and 2 

 

Example 2:

Input: str = “11100022”
Output: 0
Explanation: There is no substring with
equal number of 0 , 1 and 2.
*/

long long getSubstringWithEqual012(string str)
{
  int n = str.length();
  int numzeroes = 0, numones = 0, numtwos = 0;
  long long count = 0;

  unordered_map<string, int> mp;
  mp["0#0"] = 1;

  for (int i = 0; i < n; i++)
  {
    if (str[i] == '0')
      numzeroes++;
    else if (str[i] == '1')
      numones++;
    else
      numtwos++;

    int x = numzeroes - numones;
    int y = numzeroes - numtwos;
    string s = to_string(x) + "#" + to_string(y);

    count += mp[s]++;
  }
  return count;
}