/*
Given a Binary Tree, convert it to Binary Search Tree in such a way that keeps the original structure of Binary Tree intact.

Input Format:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:



For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output Format:
Print the inorder traversal of the the converted  binary search tree.

Your Task:
You don't need to read input or print anything. Your task is to complete the function binaryTreeToBST() which takes the root of the Binary tree as input and returns the root of the BST.

Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:

1 <= T <= 100
1 <= Number of nodes <= 1000

Example:
Sample Input:
3
1 2 3 4 
1 3 2
10 20 30 40 60

Output:
1 2 3 4 
1 2 3
10 20 30 40 60

Explanation:
Testcase 1 : The binary tree is 

          1
       /    \
     2       3
   /        
4       

The converted BST will be

        3
      /   \
    2     4
  /
1
*/
void inorder(vector<int> &v, Node *root)
{

    if (root)
    {
        inorder(v, root->left);
        v.push_back(root->data);
        inorder(v, root->right);
    }
}
void bst(Node *root, vector<int> &v, int &i)
{
    if (root)
    {
        bst(root->left, v, i);
        root->data = v[i++];
        bst(root->right, v, i);
    }
}
Node *binaryTreeToBST(Node *root)
{
    //Your code goes here
    if (root == NULL)
    {
        return NULL;
    }
    vector<int> v;
    inorder(v, root);
    sort(v.begin(), v.end());
    int i = 0;
    bst(root, v, i);
    return root;
}