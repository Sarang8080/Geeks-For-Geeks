/*
Given a Binary Tree of size N , where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree

             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

should be changed to

       20(4-2+12+6)
          /              \
     4(8-4)      12(7+5)
       /   \           /  \
     0      0       0    0

 

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N


Output:
Inorder traversal of modified tree , printed by driver code.

Your Task:
You don't need to take input. Just complete the function toSumTree() which accepts root node of the tree as a parameter and modify tree into SumTree.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <=T<= 100
1 <= N <= 104

Example:
Input:
2
3 1 2
10 20 30 40 60

Output:
0 3 0
0 100 0 150 0

*/
void toSumTree(Node *node)
{
    // Your code here

    if (node == NULL)
    {
        return;
    }
    if (node->left == NULL && node->right == NULL)
    {
        node->data = 0;
    }
    else
    {
        int left = 0, right = 0;
        if (node->left)
        {
            left = node->left->data;
            toSumTree(node->left);
            left += node->left->data;
        }
        if (node->right)
        {
            right = node->right->data;
            toSumTree(node->right);
            right += node->right->data;
        }
        node->data = left + right;
    }
}