/*
GeeksforGeeks - Binary Tree left side view
ques:-
Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /     \    /    \
  4     5   6    7
   \
     8   

Example 1:

Input:
   1
 /  \
3    2
Output: 1 3

Example 2:

Input:

Output: 10 20 40
*/

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> output;
    if(root==NULL)
    return output;
    queue<Node*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        int size = pendingNodes.size();
        int temp = size;
        while(size>0){
            Node* curr = pendingNodes.front();
            pendingNodes.pop();
            if(size==temp)
              output.push_back(curr->data);
              
              if(curr->left)
               pendingNodes.push(curr->left);
               if(curr->right)
               pendingNodes.push(curr->right);
               
               size--;
        }
    }
    return output;
   // Your code here
}
