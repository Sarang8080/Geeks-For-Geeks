/*
Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed. If you can only press the keyboard for N times (with the above four keys), write a program to produce maximum numbers of A's. That is to say, the input parameter is N (No. of keys that you can press), the output is M (No. of As that you can produce).

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N, N is the number of key.

Output:
Print maximum number of A's. Print -1, if N is greater than 75.

Constraints:
1 ≤ T ≤ 50
1 ≤ N ≤ 75

Example:
Input:
2
3
7

Output:
3
9

Explanation:
Testcase 1:  We can at most get 3 A's on screen by pressing following key sequence.
A, A, A.
Testcase 2: We can at most get 9 A's on screen by pressing following key sequence.
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl
*/
#include <bits/stdc++.h>
using namespace std;

int maxA(int N)
{
    if (N <= 6)
    {
        return N;
    }
    int dp[N];
    for (int i = 1; i <= 6; i++)
    {
        dp[i - 1] = i;
    }
    for (int i = 7; i <= N; i++)
    {
        dp[i - 1] = 0;
        for (int b = i - 3; b >= 1; b--)
        {
            int curr = (i - b - 1) * dp[b - 1];
            if (curr > dp[i - 1])
            {
                dp[i - 1] = curr;
            }
        }
    }
    return dp[N - 1];
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << maxA(n) << endl;
    }
    return 0;
}