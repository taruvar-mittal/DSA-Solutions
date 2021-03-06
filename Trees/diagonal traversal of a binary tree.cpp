/*
GeeksForGeeks - Diagonal Traversal of Binary Tree
ques- Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
Explanation:
unnamed
Diagonal Traversal of binary tree : 
 8 10 14 3 6 7 13 1 4
*/

/*struct Node
{
    int data;
    Node* left, * right;
}; */

// method 1 
vector<int> diagonal(Node *root)
{ vector<int> output;
  queue<Node*> pendingNodes;
  pendingNodes.push(root);
  while(!pendingNodes.empty()){
      Node* curr = pendingNodes.front();
      pendingNodes.pop();
      while(curr){
          output.push_back(curr->data);
          if(curr->left)
            pendingNodes.push(curr->left);
          curr=curr->right;
      }
  }
  return output;
}

//method 2 - prefer more
void findDistances(Node* root, int d, map<int,vector<int>> &helper){
    if(root==NULL)
    return;
    
    helper[d].push_back(root->data);
    findDistances(root->left,d+1,helper);
    findDistances(root->right,d,helper);
}
vector<int> diagonal(Node *root)
{
    vector<int> output;
    map<int,vector<int>> helper;
    findDistances(root,0,helper);
    for(auto m:helper){
       for(int i=0;i<m.second.size();i++){
           output.push_back(m.second[i]);
       }
    }
    return output;
}
