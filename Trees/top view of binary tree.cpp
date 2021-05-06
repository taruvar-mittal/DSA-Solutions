/*
GeeksforGeeks - Top View of Binary Tree
ques:-
Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

       1
    /     \
   2       3
  /  \    /   \
4    5  6   7

Top view will be: 4 2 1 3 7
Note: Return nodes from leftmost node to rightmost node.

Example 1:

Input:
      1
   /    \
  2      3
Output: 2 1 3
Example 2:

Input:
       10
    /      \
  20        30
 /   \    /    \
40   60  90    100
Output: 40 20 10 30 100
*/

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> output;
        if(root==NULL)
        return output;
        map<int,int> helper;
        queue<pair<Node*,int>> pendingNodes;
        pendingNodes.push(make_pair(root,0));
        while(!pendingNodes.empty()){
           
                pair<Node*,int> curr = pendingNodes.front();
                pendingNodes.pop();
               
               if(helper.find(curr.second)==helper.end())
                 helper[curr.second] = curr.first->data;
                 
                 if(curr.first->left){
                     pendingNodes.push(make_pair(curr.first->left,curr.second-1));
                 }
                  if(curr.first->right){
                     pendingNodes.push(make_pair(curr.first->right,curr.second+1));
                 }
            
        }
        for(auto it:helper){
            output.push_back(it.second);
        }
        return output;
    }

};
