/*
Leetcode 652. Find Duplicate Subtrees
ques:-
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

Example 1:

Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:

Input: root = [2,1,1]
Output: [[1]]
Example 3:

Input: root = [2,2,2,3,null,3,null]
Output: [[2,3],[3]]
*/

class Solution {
public:
    vector<TreeNode*> output;
    unordered_map<string,int> mymap;
    
    string helper(TreeNode* root){
        if(root==NULL)
            return "n";
    
        string s = to_string(root->val)+"#"+helper(root->left)+"#"+helper(root->right);
        
        if(mymap[s]==1)
            output.push_back(root);
        mymap[s]++;
        
        return s;
        
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root==NULL)
            return {};
        helper(root);
        return output;
    }
};
