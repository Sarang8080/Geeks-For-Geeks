/*
Given a simple expression tree, which is also a full binary tree consisting of basic binary operators i.e., + , – ,* and / and some integers, Your task is to evaluate the expression tree.

Input Format:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer N denoting the no of nodes. Then in the next line are N space separated values of the nodes of the Binary tree filled in continous way from the left to the right.

Output Format:
For each test case output will be the result obtained by simplifying the expression tree.

Constraints:
1 <= T <= 100
2 <= N <= 500

Your Task:
You need to complete the function evalTree which takes the root of the tree as its only argument and returns an integer denoting the result obtained by simplifying the expression tree.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Example(To be used only for expected Output):
Input:
2
7
+ * - 5 4 100 20
3
- 4 7 
Output:
100
-3

Explanation:
Testcase1:
the tree will look like


On simplification gives ((5*4) + (100-20)) = 100 .
Testcase2:
the tree will look like
      -
    /   \
  4     7
On simplification gives  4 - 7 =  -3


Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/

int evalTree(node *root)
{
    // Your code here
    int x, y;
    if (root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            return stoi(root->data);
        }
        x = evalTree(root->left);
        y = evalTree(root->right);
        if (root->data == "+")
        {
            return x + y;
        }
        if (root->data == "-")
        {
            return x - y;
        }
        if (root->data == "*")
        {
            return x * y;
        }
        if (root->data == "/")
        {
            return x / y;
        }
    }
}
