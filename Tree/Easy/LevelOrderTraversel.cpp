/*
Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should print level order traversal in spiral form.

Your Task:
The task is to complete the function printSpiral() which prints the elements in spiral form of level order traversal. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= T <= 30
0 <= Number of nodes <= 105
1 <= Data of a node <= 105

Example:
Input:
2
1 3 2  
10 20 30 40 60 
Output:
1 3 2
10 20 30 60 40 

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the spiral level order would be 1 3 2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the spiral level order would be 10 20 30 60 40
*/
void printSpiral(Node *root)
{
    //Your code here
    stack<Node *> s1;
    stack<Node *> s2;
    struct Node *temp;
    if (root == NULL)
    {
        return;
    }
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            temp = s1.top();
            cout << temp->data << " ";
            s1.pop();
            if (temp->right)
            {
                s2.push(temp->right);
            }
            if (temp->left)
            {
                s2.push(temp->left);
            }
        }
        while (!s2.empty())
        {
            temp = s2.top();
            cout << temp->data << " ";
            s2.pop();
            if (temp->left)
            {
                s1.push(temp->left);
            }
            if (temp->right)
            {
                s1.push(temp->right);
            }
        }
    }
}
