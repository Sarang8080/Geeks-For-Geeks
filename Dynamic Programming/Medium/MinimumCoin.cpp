/*

Given a value V. You have to make change for V cents, given that you have infinite supply of each of C{ C1, C2, .. , Cm} valued coins. Find the minimum number of coins to make the change.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is V and N, V is the value of cents and N is the number of coins. The second line of each test case contains N input C[i], value of available coins.

Output:
Print the minimum number of coins to make the change, if not possible print "-1".

Constraints:
1 ≤ T ≤ 100
1 ≤ V ≤ 106
1 ≤ N ≤ 106
1 ≤ C[i] ≤ 106

Example:
Input:
1
7 2
2 1

Output:
4

Explanation :
Testcase 1: We can use coin with value 2 three times, and coin with value 1 one times to change a total of 7.
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
        int V, N;
        cin >> V >> N;
        int c[N];
        for (int i = 0; i < N; i++)
        {
            cin >> c[i];
        }
        int table[V + 1];

        // Base case (If given value V is 0)
        table[0] = 0;

        // Initialize all table values as Infinite
        for (int i = 1; i <= V; i++)
            table[i] = INT_MAX;

        // Compute minimum coins required for all
        // values from 1 to V
        for (int i = 1; i <= V; i++)
        {
            // Go through all coins smaller than i
            for (int j = 0; j < N; j++)
                if (c[j] <= i)
                {
                    int sub_res = table[i - c[j]];
                    if (sub_res != INT_MAX && sub_res + 1 < table[i])
                        table[i] = sub_res + 1;
                }
        }
        if (table[V] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << table[V] << endl;
        }
    }
    return 0;
}