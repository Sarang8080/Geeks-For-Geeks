/*
Given a gold mine (M) of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\) that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right. Your task is to find out maximum amount of gold which he can collect.

Examples:

Input : M[][] = {{1, 3, 3},
                 {2, 1, 4},
                 {0, 6, 4}};
Output : 12 
{(1,0)->(2,1)->(2,2)}

Input: M[][] = {{1, 3, 1, 5},
                {2, 2, 4, 1},
                {5, 0, 2, 3},
                {0, 6, 1, 2}};
Output : 16
(2,0) -> (1,1) -> (1,2) -> (0,3) OR
(2,0) -> (3,1) -> (2,2) -> (2,3)


Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an integer n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix.

Output:
For each test case in a new line print an integer denoting the max gold the miner could collect.

Constraints:
1<=T<=100
1<=n,m<=20
1<=M[][]<=100

Example:
Input:
2
3 3 
1 3 3 2 1 4 0 6 4
2 2
1 2 3 4
Output:
12
7
*/
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int goldmine(int gold[][MAX], int m, int n)
{
    int dp[m][n];
    memset(dp, 0, sizeof(dp));
    for (int col = n - 1; col >= 0; col--)
    {
        for (int row = 0; row < m; row++)
        {
            int right = (col == n - 1) ? 0 : dp[row][col + 1];
            int r_up = (row == 0 || col == n - 1) ? 0 : dp[row - 1][col + 1];
            int r_down = (row == m - 1 || col == n - 1) ? 0 : dp[row + 1][col + 1];
            dp[row][col] = gold[row][col] + max(right, max(r_up, r_down));
        }
    }
    int res = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        if (dp[i][0] > res)
        {
            res = dp[i][0];
        }
    }
    return res;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int gold[100][100];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> gold[i][j];
            }
        }
        cout << goldmine(gold, m, n) << endl;
    }
    return 0;
}