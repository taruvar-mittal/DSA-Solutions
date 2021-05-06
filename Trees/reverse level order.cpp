/*
GeeksforGeeks - reverseLevelOrder
ques:-
Given a binary tree of size N, find its reverse level order traversal. ie- the traversal must begin from the last level.

Example 1:

Input :
        1
      /   \
     3     2

Output: 3 2 1
Explanation:
Traversing level 1 : 3 2
Traversing level 0 : 1
Example 2:

Input :
       10
      /  \
     20   30
    / \ 
   40  60

Output: 40 60 20 30 10
Explanation:
Traversing level 2 : 40 60
Traversing level 1 : 20 30
Traversing level 0 : 10
*/

vector<int> reverseLevelOrder(Node *root)
{
   vector<int> output;
   if(root==NULL)
     return output;
   queue<Node*> pendingNodes;
   pendingNodes.push(root);
   while(!pendingNodes.empty()){
       Node* curr = pendingNodes.front();
       pendingNodes.pop();
       output.push_back(curr->data);
       if(curr->right)
        pendingNodes.push(curr->right);
       if(curr->left)
        pendingNodes.push(curr->left);
   }
   reverse(output.begin(),output.end());
   return output;
}
