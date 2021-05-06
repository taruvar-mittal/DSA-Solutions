/*
Leetcode 968 - Binary Tree Cameras
ques:-
Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

Example 1:

Input: [0,0,null,0,0]
Output: 1
Explanation: One camera is enough to monitor all nodes if placed as shown.
Example 2:


Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
*/

class Solution {
public:
    int ans = 0;
    // leaf node - 0
    // with camera - 1
    // no camera but being watched - 2
    
    int helper(TreeNode* root){
        if(root==NULL)
            return 2;
        
        int leftchild = helper(root->left);
        int rightchild = helper(root->right);
        
        if(leftchild==0 && rightchild==0){
            ans++;
            return 1;
        }else if((leftchild==0 && rightchild==1)||(leftchild==1 && rightchild==0)){
            ans++;
            return 1;
        }else if((leftchild==0 && rightchild==2)||(leftchild==2 && rightchild==0)){
            ans++;
            return 1;
        }else if(leftchild==1 && rightchild==1){
            return 2;
        }else if((leftchild==1 && rightchild==2)||(leftchild==2 && rightchild==1)){
            return 2;
        }else
            return 0; //leftchild==2 && rightchild==2;
        
    }
    
    int minCameraCover(TreeNode* root) {
        int temp = helper(root);
        if(temp==0)
            ans++;
    
        return ans;
    }
};
