/*
Leetcode 449. Serialize and Deserialize BST
ques:-
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible. 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []
*/

class Codec {
    private:
       TreeNode* helper(stringstream& ss){
           string s;
           ss >> s;
           
           if(s=="#")
               return NULL;
           
           TreeNode* root = new TreeNode(stoi(s));
           root->left = helper(ss);
           root->right = helper(ss);
           return root;
       }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return " #";
        
        string s = " ";
        s += to_string(root->val);
        
        s+=serialize(root->left);
        s+=serialize(root->right);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return helper(ss);
    }
};

