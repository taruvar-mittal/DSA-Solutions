/*
Leetcode 116 - for perfect binary tree
ques:- You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Follow up:
You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.



Leetcode 117 - for any binary tree
ques:- Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// for a perfect binary tree
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        Node* temp = root;
        while(root->left){
           Node* tnode = root;
           while(tnode!=NULL){
               tnode->left->next = tnode->right;
               if(tnode->next!=NULL){
                   tnode->right->next = tnode->next->left;
               }
               tnode=tnode->next;
           }
            root=root->left;
        }
        return temp;
    }
};

//for any binary tree
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*> pendingNodes;
        pendingNodes.push(root);
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            while(size>0){
                Node* curr = pendingNodes.front();
                pendingNodes.pop();
                if(size!=1)
                    curr->next = pendingNodes.front();
                if(curr->left) pendingNodes.push(curr->left);
                if(curr->right) pendingNodes.push(curr->right);
                size--;
            }
        }
        return root;
    }
};
