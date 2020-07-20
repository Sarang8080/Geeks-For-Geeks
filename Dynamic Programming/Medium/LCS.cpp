/*
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.

LCS of "ABC" and "AC" is "AC" of length 2
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        char s1[m];
        char s2[n];
        for (int i = 0; i < m; i++)
        {
            cin >> s1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> s2[i];
        }
        int L[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    L[i][j] = 0;
                }
                else if (s1[i - 1] == s2[j - 1])
                {
                    L[i][j] = 1 + L[i - 1][j - 1];
                }
                else
                {
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }
            }
        }
        cout << L[m][n] << endl;
    }
    return 0;
}