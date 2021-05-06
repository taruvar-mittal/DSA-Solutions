/*
Leetcode 145
Ques:- Given the root of a binary tree, return the postorder traversal of its nodes' values.
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
    //using recursion
    void helper(TreeNode* root, vector<int> &output){
        if(root==NULL)
            return;
        helper(root->left,output);
        helper(root->right,output);
        output.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        helper(root, output);
        return output;
    }
    
    // without recursion using stack
    vector<int> postorderTraversal(TreeNode* root){
        if(root==NULL)
            return {};
        vector<int> output;
       stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* curr = s.top();
            s.pop();
            output.push_back(curr->val);
            if(curr->left)
                s.push(curr->left);
            if(curr->right){
                s.push(curr->right);
            }
        }
        reverse(output.begin(),output.end());
        return output;
    }
    
    // without stack without recursion - morris traversal
    // morris traversal is not possible for postorder method. However we can do morris printing by using reverse preorder technique
    // this is not the correct method because we are not finding postorder directly, but using preorder to find it
     vector<int> postorderTraversal(TreeNode* root){
         vector<int> output;
         while(root){
             if(root->right==NULL){
                 output.push_back(root->val);
                 root=root->left;
             }else{
                 TreeNode* rootp1 = root->right;
                 while(rootp1->left!=NULL && rootp1->left!=root){
                     rootp1=rootp1->left;
                 }
                 if(rootp1->left==NULL){
                     rootp1->left = root;
                     output.push_back(root->val);
                     root=root->right;
                 }else{
                     rootp1->left = NULL;
                     root = root->left;
                 }
             }
         }
         reverse(output.begin(),output.end());
         return output;
     }
};
