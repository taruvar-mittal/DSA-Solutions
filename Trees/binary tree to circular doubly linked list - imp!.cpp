/*
geeksforGeeks - Binary Tree to circular Doubly Linked List
ques:-
Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List(CDLL) in-place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted CDLL. The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.

Example 1:

Input:
      1
    /   \
   3     2
Output:
3 1 2 
2 1 3
Explanation: After converting tree to CDLL
when CDLL is is traversed from head to
tail and then tail to head, elements
are displayed as in the output.
Example 2:

Input:
     10
   /    \
  20    30
 /  \
40  60
Output:
40 20 60 10 30 
30 10 60 20 40
Explanation:After converting tree to CDLL,
when CDLL is is traversed from head to
tail and then tail to head, elements
are displayed as in the output.
*/

class Solution
{
  public:
    //Function to convert binary tree into circular doubly linked list.
    Node* join(Node* leftlist, Node* rightlist){
        if(leftlist==NULL)
          return rightlist;
        if(rightlist==NULL)
          return leftlist;
        
        Node* leftend = leftlist->left;
        Node* rightend = rightlist->left;
        
        leftend->right = rightlist;
        rightlist->left = leftend;
        
        leftlist->left = rightend;
        rightend->right = leftlist;
        return leftlist;
    }
    Node *bTreeToCList(Node *root)
    {
        if(root==NULL)
        return NULL;
        
        Node* left = bTreeToCList(root->left);
        Node* right = bTreeToCList(root->right);
      
      root->left=root->right=root;
      return join(join(left,root),right);
 
    }
};
