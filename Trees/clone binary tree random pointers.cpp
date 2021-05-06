/*
Geeks for Geeks
ques:- Given a special binary tree having random pointers along with the usual left and right pointers. Clone the given tree.
*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/

class Solution{
  public:
  
  Node* leftRight(Node* tree, unordered_map<Node*,Node*> &helper){
      if(tree==NULL)
      return tree;
      
      Node* newnode = new Node(tree->data);
      helper[tree] = newnode;
      newnode->left = leftRight(tree->left,helper);
      newnode->right = leftRight(tree->right,helper);
      return newnode;
  }
  
  void random(Node* tree, Node* root, unordered_map<Node*, Node*> helper){
      if(root==NULL)
        return;
        
        root->random = helper[tree->random];
        random(tree->left,root->left,helper);
        random(tree->right,root->right,helper);
  }
   
    Node* cloneTree(Node* tree)
    {
        unordered_map<Node*,Node*> helper;
        Node* root = leftRight(tree,helper);
        random(tree,root,helper);
        return root;
    }
};
