/* 
GeeksforGeeks - diagonal sum binary tree
ques:- Consider lines of slope -1 passing between nodes (dotted lines in below diagram). 
The diagonal sum in a binary tree is the sum of all node’s data lying between these lines. Given a Binary Tree, print all diagonal sums.
*/

void helper(struct Node* root, int d, map<int,int>& output){
    if(root==NULL)
    return;
    
    output[d]+=root->data;
    helper(root->left,d+1,output);
    helper(root->right,d,output);
}

vector<int> diagonalSum(struct Node* root)
{
    map<int,int> output;
    vector<int> result;
    helper(root,0,output);
    for(auto s:output){
        result.push_back(s.second);
    }
    return result;
}
