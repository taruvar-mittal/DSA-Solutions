/*
Leetcode 508. Most Frequent Subtree Sum
ques:-
Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.

The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

Example 1:

Input: root = [5,2,-3]
Output: [2,-3,4]
Example 2:

Input: root = [5,2,-5]
Output: [2]
*/

class Solution {
public:
    int helper(TreeNode* root, unordered_map<int,int>& freq, int& maxfreq){
        if(root==NULL)
            return 0;
        
        int subtreesum = root->val+helper(root->left,freq,maxfreq)+helper(root->right,freq,maxfreq);
        
        freq[subtreesum]++;
        maxfreq = max(maxfreq,freq[subtreesum]);
        return subtreesum;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> output;
        unordered_map<int,int> freq;
        int maxfreq = INT_MIN;
        int subtreesum = helper(root,freq,maxfreq);
        
        for(auto it:freq){
            if(it.second == maxfreq)
                output.push_back(it.first);
        }
        return output;
    }
};
