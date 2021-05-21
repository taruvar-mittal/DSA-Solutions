/*
839. Similar String Groups
ques:-
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?

Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1
*/

class Solution {
public:
    bool comp(string& a, string& b){
        if(a.length()!=b.length())
            return false;
        int n = 0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i])
                n++;
            if(n>2)
                return false;
        }
        return true;
    }
    
    void dfs(unordered_map<int,vector<int>>& graph, vector<int>& visited, int i){
        visited[i] = 1;
        for(int x=0;x<graph[i].size();x++){
            if(!visited[graph[i][x]])
            dfs(graph,visited,graph[i][x]);
        }
    }
    
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,vector<int>> graph;
        int n = strs.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(comp(strs[i],strs[j])){
                  graph[i].push_back(j);
                  graph[j].push_back(i);
                }
            }
        }
        
        int count = 0;
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                dfs(graph,visited,i);
            }
        }
        return count;
    }
};

