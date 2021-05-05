/*
GeeksforGeeks - foldable binary tree
ques:-
Given a binary tree, check if the tree can be folded or not. A tree can be folded if left and right subtrees of the tree are structure wise same. An empty tree is considered as foldable.
Consider the below trees:
(a) and (b) can be folded.
(c) and (d) cannot be folded.


(a)
       10
     /    \
    7      15
     \    /
      9  11
(b)
        10
       /  \
      7    15
     /      \
    9       11
(c)
        10
       /  \
      7   15
     /    /
    5   11
(d)
         10
       /   \
      7     15
    /  \    /
   9   10  12
 
Example 1:

Input:
     10
    /    \
   7     15
 /  \   /  \
N   9  11   N
Output:Yes
Example 2:

Input:
      10
    /    \
   7     15
 /  \   /  \
5   N  11   N
Output: No

*/

bool check(Node* root1,Node* root2){
    if(root1==NULL && root2==NULL)
      return true;
    if(root1==NULL || root2==NULL)
      return false;
      
      return check(root1->left,root2->right)&&check(root1->right,root2->left);
}
bool IsFoldable(Node* root)
{
    if(root==NULL)
    return true;
    return check(root->left,root->right);

}


