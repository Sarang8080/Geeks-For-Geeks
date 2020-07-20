/*
There are N stairs, and a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, the person can reach the top (order does not matter).
Note: Order does not matter means for n=4 {1 2 1},{2 1 1},{1 1 2} are considered same.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test case, an integer N will be given.

Output:
For each testcase, in a new line, print the number of possible ways to reach Nth stair.

User Task:
Your task is to complete the function countWays() which takes single argument(N) and returns the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= T <= 1000
1 <= N <= 106

Example:
Input:
2
4
5
Output:
3
3
*/
long long countWays(int m)
{
    // your code here
    int dp[m + 1];
    for (int i = 0; i <= m; i++)
        dp[i] = 0;
    dp[0] = 1;

    for (int i = 1; i <= m; i++)
    {
        dp[i] += dp[i - 1];
    }
    for (int i = 2; i <= m; i++)
    {
        dp[i] += dp[i - 2];
    }
    return dp[m];
}