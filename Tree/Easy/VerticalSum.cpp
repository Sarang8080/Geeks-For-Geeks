/*
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.
For Example:
 

       1
    /   \
  2      3
 / \    / \
4   5  6   7
The tree has 5 vertical lines
Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Single line output, print the vertical sum of given tree.

Your Task:
You don't need to take input. Just complete the function verticalSum() that takes root node of the tree as parameter and returns an array containing the vertical sum of tree from left to right.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1<=T<=1000
1<=N<=1000

Example:
Input:
2
1 2 3 4 5 6 7
5 2 3 1 7 6 N
Output:
4 2 12 3 7 
1 2 18 3 
*/
void hdistance(Node *root, map<int, int> &m, int hd)
{
    if (root == NULL)
    {
        return;
    }
    m[hd] += root->data;
    hdistance(root->left, m, hd - 1);
    hdistance(root->right, m, hd + 1);
}
void verticalSum(Node *root)
{
    // add code here.
    if (root == NULL)
    {
        return;
    }
    map<int, int> m;
    hdistance(root, m, 0);
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << " ";
    }
}