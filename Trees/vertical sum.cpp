/*
GeeksforGeeks - vertical sum
ques:-
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.

Example 1:

Input:
       1
    /   \
  2      3
 / \    / \
4   5  6   7
Output: 
Explanation:
The tree has 5 vertical lines
Vertical-Line-1 has only one node
4 => vertical sum is 4
Vertical-Line-2: has only one node
2=> vertical sum is 2
Vertical-Line-3: has three nodes:
1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3
=> vertical sum is 3
Vertical-Line-5: has only one node 7
=> vertical sum is 7
*/

class Solution{
  public:
    vector <int> verticalSum(Node *root) {
        map<int,vector<int>> helper;
        queue<pair<Node*, int>> pendingNodes;
        pendingNodes.push(make_pair(root,0));
        while(!pendingNodes.empty()){
            int size = pendingNodes.size();
            while(size--){
                pair<Node*,int> curr = pendingNodes.front();
                pendingNodes.pop();
                helper[curr.second].push_back(curr.first->data);
                if(curr.first->left)
                 pendingNodes.push(make_pair(curr.first->left,curr.second-1));
                if(curr.first->right)
                  pendingNodes.push(make_pair(curr.first->right,curr.second+1));
            }
        }
        vector<int> output;
        for(auto it:helper){
            vector<int> v= it.second;
            int sum = 0;
            for(int i= 0;i<v.size();i++)
              sum+=v[i];
              
              output.push_back(sum);
        }
        return output;
    }
};
