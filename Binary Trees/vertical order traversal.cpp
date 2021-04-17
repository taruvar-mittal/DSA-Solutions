/*
Leetcode 987 - Vertical order traversal of binary tree
ques- 
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column.
There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
Return the vertical order traversal of the binary tree.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, int c, int r, map<int,map<int,vector<int>>>& mymap){
        if(root==NULL)
            return;
        
        mymap[c][r].push_back(root->val);
        helper(root->left,c-1,r+1,mymap);
        helper(root->right,c+1,r+1,mymap);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> output;
        map<int,map<int,vector<int>>> mymap;
        helper(root,0,0,mymap);
        
        for(auto m:mymap){
            vector<int> temp;
            for(auto v:m.second){
                sort(v.second.begin(),v.second.end());
                for(int i=0;i<v.second.size();i++){
                    temp.push_back(v.second[i]);
                }
            }
            output.push_back(temp);
        }
        return output;
    }
};
