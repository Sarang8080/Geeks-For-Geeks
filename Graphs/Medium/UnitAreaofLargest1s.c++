/* Consider a matrix with N rows and M columns, where each cell contains either a ‘0’ or a ‘1’ and any cell containing a 1 is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. If one or more filled cells are connected, they form a region. The task is to find the unit area of the largest region.

Input:
The first line of input will be the number of testcases T, then T testcases follow. The first line of each testcase contains 2 space separated integers n and m. Then in the next line are the n x m inputs of the matrix A separated by space.

Output:
The output in the expected output will be the length of the largest region formed.

Constraints:
1 <= T <= 100
1 <= N, M <= 50
0 <= A[][] <= 1

Example:
Input:
2
3 3
1 1 0 0 0 1 1 0 1
1 3
1 1 1

Output:
4
3

Explanation:
Testcase 1: Matrix can be shown as follows:
1 1 0
0 0 1
1 0 1

Largest region of 1s in the above matrix is with total 4 1s (colored in Red). 
*/
#include <iostream>
using namespace std;
#define MAX 51
void regions(int a[][MAX], int m, int n, int i, int j, int &count)
{
    if (a[i][j] == 0 || i < 0 || j < 0 || i >= m || j >= n)
        return;
    count++;
    a[i][j] = 0;
    regions(a, m, n, i, j - 1, count);
    regions(a, m, n, i, j + 1, count);
    regions(a, m, n, i - 1, j, count);
    regions(a, m, n, i - 1, j - 1, count);
    regions(a, m, n, i - 1, j + 1, count);
    regions(a, m, n, i + 1, j, count);
    regions(a, m, n, i + 1, j - 1, count);
    regions(a, m, n, i + 1, j + 1, count);
}
//cout<<" count "<<count<<endl; }="" int="" main()="" {="" int="" t;="" cin="">>t;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, n;
        int res, r, count;
        res = 0;
        cin >> m >> n;
        int a[MAX][MAX];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    count = 0;
                    regions(a, m, n, i, j, count);
                    if (count >= res)
                        res = count;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
