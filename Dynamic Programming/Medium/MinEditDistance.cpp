/*
Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required to convert ‘str1′ into ‘str2′.

Insert
Remove
Replace
All of the above operations are of cost=1.
Both the strings are of lowercase.

Input:
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1

Explanation:
Testcase 1: One operation is required to make 2 strings same i.e. removing 's' from str2.
*/
#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z)
{
    return min(min(x, y), z);
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
        char c1[m];
        char c2[n];
        for (int i = 0; i < m; i++)
        {
            cin >> c1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> c2[i];
        }
        int T[m + 1][n + 1];
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                {
                    T[i][j] = j;
                }
                else if (j == 0)
                {
                    T[i][j] = i;
                }
                else if (c1[i - 1] == c2[j - 1])
                {
                    T[i][j] = T[i - 1][j - 1];
                }
                else
                {
                    T[i][j] = 1 + min(T[i - 1][j - 1], T[i - 1][j], T[i][j - 1]);
                }
            }
        }
        cout << T[m][n] << endl;
    }
    return 0;
}