/*
Given a String, find the longest palindromic subsequence

Input:
The first line of input contains an integer T, denoting no of test cases. The only line of each test case consists of a string S(only lowercase)

Output:
Print the Maximum length possible for palindromic subsequence.

Constraints:
1<=T<=100
1<=|Length of String|<=1000
 

Examples:
Input:
2
bbabcbcab
abbaab
Output:
7
4
*/
#include <bits/stdc++.h>
using namespace std;

int lis(string s)
{
    int n = s.size();
    int dp[n][n];
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    for (int l = 2; l <= n; l++)
    {
        for (int i = 0; i <= n - l; i++)
        {
            int j = i + l - 1;
            if (s[i] == s[j] && l == 2)
            {
                dp[i][j] = 2;
            }
            else if (s[i] == s[j])
            {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << lis(s) << endl;
    }
    return 0;
}