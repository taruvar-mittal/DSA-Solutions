/*
Leetcode 1305 - All Elements in two binary search trees
ques:-
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]
*/

class Solution {
public:
    void helper(TreeNode* root, vector<int> & output){
        if(root==NULL)
            return;
        
        helper(root->left,output);
        output.push_back(root->val);
        helper(root->right,output);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        vector<int> output;
        helper(root1,v1);
        helper(root2,v2);
        merge(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(output));
        return output;
    }
};
