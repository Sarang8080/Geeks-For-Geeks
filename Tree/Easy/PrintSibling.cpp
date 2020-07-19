/*
Given a Binary Tree of size N, such that all nodes have distinct values, print all the nodes which don't have a sibling node in sorted order. If all nodes have a sibling node then print -1 .
Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:
  
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each test case , print all the nodes which don't have a sibling node in the sorted order. If all nodes have a sibling node then print -1.
Your Task:
You don't have to take input. Complete the function printSibling() that takes root node of the tree as parameter and prints all the space seperated sorted nodes which don't have a sibling node in the sorted order.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 104

Example:
Input
2
37 20 N 113 
1 2 3
Output 
20 113
-1
Explanation:
Testcase 1: In above example the root node is 37 which has left child 20 and right child nothing. The node 20 has a left child 113. So, the aswer is 2 that is node 20 and 113 don't have siblings.
*/
void printSibling(Node *node)
{
    // Your code here
    vector<int> v;
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();

        if (temp->left != NULL && temp->right == NULL)
        {
            v.push_back(temp->left->data);
        }
        if (temp->left == NULL && temp->right != NULL)
        {
            v.push_back(temp->right->data);
        }
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
    if (v.size() == 0)
    {
        cout << "-1";
    }
    else
    {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
    }
}