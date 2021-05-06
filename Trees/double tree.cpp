/*
GeeksforGeeks - double tree
ques:-
Write a program that converts a given tree to its Double tree. To create Double tree of the given tree, create a new duplicate for each node, and insert the duplicate as the left child of the original node.

So the tree…

    2
   / \
  1   3
is changed to…

       2
      / \
     2   3
    /   /
   1   3
  /
 1
And the tree

            1
          /   \
        2      3
      /  \
    4     5
is changed to



               1
             /   \
           1      3
          /      /
        2       3
      /  \
     2    5
    /    /
   4   5
  /   
 4    
 */
 
 void doubleTree(node* Node)
{
	if(Node==NULL)
	return;
	
	doubleTree(Node->left);
	doubleTree(Node->right);
	
	node* temp = Node->left;
	Node->left = newNode(Node->data);
	Node->left->left = temp;
	
}
