/*
geeksforGeeks - binary tree to BST
ques:-
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.
 

Example 1:

Input:
      1
    /   \
   2     3
Output: 1 2 3

Example 2:

Input:
          1
       /    \
     2       3
   /        
 4       
Output: 1 2 3 4
Explanation:
The converted BST will be

        3
      /   \
    2     4
  /
 1
 */
 
 class Solution{
  public:
    void findInorder(Node* root, vector<Node*>& inorder1){
        if(root==NULL)
          return;
          
        findInorder(root->left,inorder1);
        inorder1.push_back(root);
        findInorder(root->right,inorder1);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<Node*> inorder1;
        findInorder(root,inorder1);
        vector<int> inorder2;
        for(int i=0;i<inorder1.size();i++){
            inorder2.push_back(inorder1[i]->data);
        }
        sort(inorder2.begin(),inorder2.end());
        for(int i=0;i<inorder1.size();i++){
            inorder1[i]->data = inorder2[i];
        }
        return root;
    }
};
