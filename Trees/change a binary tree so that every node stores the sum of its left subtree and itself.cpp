/*
GeeksforGeeks
ques:- Given a Binary Tree, change the value in each node to sum of all the values in the nodes in the left subtree including its own.
*/

int updatetree(node *root)
{
    if(root==NULL)
    return 0;
    
    int lsum = updatetree(root->left);
    int rsum = updatetree(root->right);
    
    root->data = root->data + lsum;
    return root->data + rsum;
}




