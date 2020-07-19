/*
Given a Binary Tree. Find the difference between the sum of node values at even levels and the sum of node values at the odd levels.
       2
     /    \
    3     5
For the above tree the odd level sum is 2 and even level sum is 8 thus the difference is 2-8=-6

Input:

First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should return an integer denoting the difference between the sum of nodes at odd level and the sum of nodes at even level

Your Task:
This is a function problem. You don't have to take input. Just complete the function getLevelDiff() that takes root as parameter and returns the answer. The printing is done by the driver code only.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 105

Example:
Input
2
1 2 3
10 20 30 40 60
Output
-4
60

The first case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2. 
*/
int getLevelDiff(Node *root)
{
    //Your code here
    queue<Node *> q;
    struct Node *temp;
    int sumE = 0, sumO = 0;
    int size;
    int flag = 0;
    if (root == NULL)
    {
        return 0;
    }

    q.push(root);
    while (!q.empty())
    {
        size = q.size();
        while (size--)
        {
            temp = q.front();
            q.pop();
            if (flag == 0)
            {
                sumO += temp->data;
            }
            else
            {
                sumE += temp->data;
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        if (flag == 0)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }

    return sumO - sumE;
}
