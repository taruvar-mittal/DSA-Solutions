/*
 Leetcode 94
 Ques - Given the root of a binary tree, return the inorder traversal of its nodes' values.
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
    
    // using recursion
     void helper(TreeNode* root, vector<int> &output){
         if(root==NULL)
             return;
         helper(root->left,output);
         output.push_back(root->val);
        helper(root->right,output);
     }
   
     vector<int> inorderTraversal(TreeNode* root) {
       vector<int> output;
        helper(root, output);
        
        return output;
     }
    
    
    // without recursion using stack
     vector<int> inorderTraversal(TreeNode* root) {
       vector<int> output;
        stack<TreeNode*> s;
         TreeNode* curr = root;
         while(!s.empty() || curr!=NULL){
             while(curr!=NULL){
                s.push(curr);
                 curr=curr->left;
             }
            curr = s.top();
             s.pop();
             output.push_back(curr->val);
             curr=curr->right;
         }
         return output;
    }
    
    
    // without recursion without stack - Morris Traversal
     vector<int> inorderTraversal(TreeNode* root){
         vector<int> output;
         while(root){
             if(root->left==NULL){
                 output.push_back(root->val);
                 root=root->right;
             }else{
                 TreeNode* rootp1 = root->left;
                 while(rootp1->right!=NULL && rootp1->right!=root)
                     rootp1=rootp1->right;
                 if(rootp1->right == NULL){
                     rootp1->right=root;
                     root=root->left;
                 }else{
                     rootp1->right=NULL;
                     output.push_back(root->val);
                     root=root->right;
                 }
             }
         }
         return output;
     }
};
