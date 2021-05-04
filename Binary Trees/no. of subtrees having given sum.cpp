/*
GeeksforGeeks - no. of subtrees having given sum
ques:-
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
Example: For the tree given below:            

              5
            /    \
        -10     3
        /    \    /  \
      9     8  -4 7

Subtree with sum 7:
             -10
            /      \
          9        8

and one node 7.

Example 1:

Input:
       5
    /    \
  -10     3
 /   \   /  \
 9   8 -4    7
X = 7
Output: 2
Explanation: Subtrees with sum 7 are
[9, 8, -10] and [7] (refer the example
in the problem description).
Example 2:

Input:
    1
  /  \
 2    3
X = 5
Output: 0
Explanation: No subtree has sum equal
to 5.
*/

int helper(Node* root, int X,int& output){
    if(root==NULL)
    return 0;
    
    int currsum = root->data+helper(root->left,X,output)+helper(root->right,X,output);
    if(currsum==X)
    output++;
    return currsum;
}
int countSubtreesWithSumX(Node* root, int X)
{
    int output = 0;
    int subtreesum = helper(root,X,output);
    return output;
}
