/*
Leetcode 1339 - Maximum Product of Splitted Binary Tree
ques:-
Given a binary tree root. Split the binary tree into two subtrees by removing 1 edge such that the product of the sums of the subtrees are maximized.

Since the answer may be too large, return it modulo 10^9 + 7.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 110
Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
Example 2:
Input: root = [1,null,2,3,4,null,null,5,6]
Output: 90
Explanation:  Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
Example 3:

Input: root = [2,3,9,10,7,8,6,5,4,11,1]
Output: 1025
Example 4:

Input: root = [1,1]
Output: 1
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
    const unsigned int m = 1000000007;
    long long ans = 0;
    long long findTotalSum(TreeNode* root){
        if(root==NULL)
            return 0;
        
        return root->val+findTotalSum(root->left)+findTotalSum(root->right);
    }
    
    long long findSubtreeSum(TreeNode* root,long long totalsum){
        if(root==NULL)
            return 0;
        
        long long currsum = root->val+findSubtreeSum(root->left,totalsum)+findSubtreeSum(root->right,totalsum);
        
        ans = max(ans,currsum*(totalsum-currsum));
        return currsum;
        
    }
    
    int maxProduct(TreeNode* root) {
        long long totalsum = findTotalSum(root);
        
        long long subtreeSum = findSubtreeSum(root,totalsum);
        return ans%m;
    }
};
