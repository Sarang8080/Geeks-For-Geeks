/*
Given two strings S and T, find count of distinct occurrences of T in S as a sub-sequence. Your task is to complete the function subsequenceCount which takes two strings as argument S and T and returns the count of the sub-sequences.

Input:
The first line of input contains an integer t denoting the no of test cases . Then t test cases follow. The first line of each test case contains 2 strings S and T.

Output:
For each test case in a new line print the count of distinct occurrences of T in S as a sub-sequence.
Since the count can be quite large, return the count modulo 109 + 7.

Your Task:
Complete the function subsequenceCount() which takes the two strings as input parameters and returns the count modulo 109 + 7.

Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<=t<=100
1<=length of(T)<=100
1<=length of(S)<=8000

Example(To be used only for expected output):
Input
2
banana ban
geeksforgeeks ge
Output
3
6
Explanation:
(i) For first test case  S = banana, T = ban there are 3 sub-sequences which are [ban], [ba n], [b an].
(ii) For second test case S = geeksforgeeks, T=ge there are 6 sub-sequences which are  [ge], [ ge], [g e], [g e] [g e] and [ g e].
*/
int subsequenceCount(string S, string T)
{
    //Your code here
    int n = S.size();
    int m = T.size();
    int dp[m + 1][n + 1];
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (T[i - 1] != S[j - 1])
            { //case 1 , last characters different
                dp[i][j] = dp[i][j - 1];
                dp[i][j] %= 1000000007;
            }
            else
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                dp[i][j] %= 1000000007; // case 2, last characters same
            }
        }
    }
    return dp[m][n];
}
