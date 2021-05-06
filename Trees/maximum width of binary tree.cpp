/*
GeeksforGeeks - maximum width of binary tree
ques:-
Given a Binary Tree, find the maximum width of it. Maximum width is defined as the maximum number of nodes in any level.
For example, maximum width of following tree is 4 as there are 4 nodes at 3rd level.

          1
       /     \
     2        3
   /    \    /    \
  4    5   6    7
    \
      8

Example 1:

Input:
       1
     /    \
    2      3
Output: 2
Example 2:

Input:
        10
      /     \
    20      30
   /    \
  40    60
Output: 2
*/

class Solution
{
    public:
    //Function to get the maximum width of a binary tree.
    int getMaxWidth(Node* root)
    {
        int ans = 0;
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            ans = max(ans,size);
            while(size--){
                Node* curr = pendingNodes.front();
                pendingNodes.pop();
                if(curr->left)
                pendingNodes.push(curr->left);
                if(curr->right)
                pendingNodes.push(curr->right);
            }
        }
        return ans;
    }
};

