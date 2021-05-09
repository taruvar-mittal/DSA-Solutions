/*
Leetcode 297. Serialize and Deserialize Binary Tree
ques:-
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Example 1:
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
Example 4:

Input: root = [1,2]
Output: [1,2]
*/

class Codec {
public:
    string serialize(TreeNode* root)
	{
		if (root == nullptr) return "null";
		return ::to_string(root->val) + ' ' + serialize(root->left) + ' ' + serialize(root->right) + ' ';
	}


	TreeNode* deserialize(string data)
	{
		stringstream ss(data);
		return deserialize(ss);
	}

protected:
	TreeNode* deserialize(stringstream& ss)
	{
		string s;
		if (!(ss >> s) || s == "null") return nullptr;
		TreeNode* node = new TreeNode(::stoi(s));
		node->left = deserialize(ss);
		node->right = deserialize(ss);
		return node;
	}
};
