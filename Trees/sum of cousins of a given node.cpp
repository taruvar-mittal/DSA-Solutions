/*
GeeksforGeeks 
ques:-
Given a binary tree and data value of a node. The task is to find the sum of cousin nodes of given node. If given node has no cousins then return -1.
Note: It is given that all nodes have distinct values and the given node exists in the tree.

Examples:

Input: 
                1
              /  \
             3    7
           /  \  / \
          6   5  4  13
             /  / \
            10 17 15
         key = 13
Output: 11
Cousin nodes are 5 and 6 which gives sum 11. 

Input:
                1
              /  \
             3    7
           /  \  / \
          6   5  4  13
             /  / \
            10 17 15
           key = 7
Output: -1
No cousin nodes of node having value 7.
*/


int findCousinSum(Node* root, int key)
{
    if(root==NULL || root->data==key)
      return -1;

    queue<Node*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        int size = pendingNodes.size();
        bool flag = false;
        int currsum = 0;
        while(size--){
            Node* curr = pendingNodes.front();
            pendingNodes.pop();
            
            if((curr->left!=NULL && curr->left->data==key) || (curr->right!=NULL && curr->right->data==key))
              flag = true;
            else{
                if(curr->left){
                    currsum+=curr->left->data;
                     pendingNodes.push(curr->left);
                }
                 
                if(curr->right){
                     currsum+=curr->right->data;
                     pendingNodes.push(curr->right);
                }
                
            }  
        }
        if(flag){
            if(currsum==0)
              return -1;
            else
              return currsum;
        }
    }
    return -1;
}
