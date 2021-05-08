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

//method 1 - using extra space

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


// method 2 - inplace (pepcoding solution)
class Solution{
  public:
    /* The function should clone the passed tree and return 
       root of the cloned tree */
       void modifyTree(Node* tree){
           if(tree==NULL)
           return;
           
           Node* newnode = new Node(tree->data);
           newnode->left = tree->left;
           tree->left = newnode;
           modifyTree(tree->left->left);
           modifyTree(tree->right);
       }
       
       void setRandom(Node* tree){
           if(tree==NULL)
           return;
           
           tree->left->random = tree->random;
           setRandom(tree->left->left);
           setRandom(tree->right);
       }
       
       Node* recoverTree(Node* tree){
           if(tree==NULL)
             return NULL;
             
           Node* newleft = recoverTree(tree->left->left);
           Node* rootp1 = tree->left;
           tree->left = tree->left->left;
           rootp1->left = newleft;
           rootp1->right = recoverTree(tree->right);
           return rootp1;
       }
       
    Node* cloneTree(Node* tree)
    {
        modifyTree(tree);
        setRandom(tree);
        return recoverTree(tree);
    }
};

