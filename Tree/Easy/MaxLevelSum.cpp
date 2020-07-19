/*
Given a Binary Tree having positive and negative nodes. Find the maximum sum of any level in the given Binary Tree.

Examples:

Input :               4
                    /   \
                   2    -5
                  / \    /\
                -1   3 -2  6
Output: 6
Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 2'th level is 6
Hence maximum sum is 6

Input :          1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7  
Output :  17
Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:
  
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N


Output:
The function should return max sum level in the tree.

Your Task: 
You don't need to read input or print anything. Your task is to complete the function maxLevelSum() which takes the root node of the Binary Tree as input and returns the maximum sum of any horizontal level in the given Binary Tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <=T<= 100
1 <=Number of nodes<= 104
-1000 <=Data of a node<= 1000

Example(To be used only for expected output):
Input:
2
4 2 -5 -1 3 -2 6
1 2 3 4 5 N 8 N N N N 6 7
Output:
6
17
*/
int maxLevelSum(Node *root)
{
    // Your code here
    int result = root->data;
    int size;
    struct Node *temp;
    queue<Node *> q;
    int sum;
    if (root == NULL)
    {
        return NULL;
    }
    q.push(root);

    while (!q.empty())
    {
        size = q.size();
        sum = 0;
        while (size--)
        {
            temp = q.front();
            q.pop();
            sum += temp->data;

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        result = max(sum, result);
    }
    return result;
}