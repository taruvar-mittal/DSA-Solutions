/* https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/text-processing/z-algorithm-for-pattern-searching-official/ojquestion
Z Algorithm For Pattern Searching
ques:-
1. You are given two strings s1 and s2.
2. s1 represents a text and s2 represents a pattern. 
3. You have to print the starting index for all occurrences of the pattern in the given text string.
Input Format
Two strings s1 and s2 in two different lines.
Output Format
Starting index for all occurrences of the pattern in the given text string.

  COMMENTConstraints
1 <= length of the strings <= 10^4
Sample Input
abab
ab
Sample Output
0
2
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(string text,string pattern){
    vector<int> output;
    string temp = pattern + "#" + text;
    
    int n = temp.length();
    vector<int> z(n,0);
    
    int l=0,r=0;
    
    for(int i=1;i<n;i++){
        if(i<=r){
            z[i] = min(i-l,r-i+1);
        }
        
        while(i+z[i]<n && temp[i+z[i]] == temp[z[i]]){
            z[i]++;
        }
        
        if(i+z[i]-1 >r){
            l = i;
            r = i+z[i]-1;
        }
    }
    
    for(int i=0;i<n;i++){
        if(z[i]==pattern.length())
        output.push_back(i-pattern.length()-1);
    }
    
    return output;
}

int main(){
    string text,pat;
    cin>>text>>pat;
    
    vector<int> output = solve(text,pat);
    for(auto i:output){
        cout<<i<<endl;
    }
}