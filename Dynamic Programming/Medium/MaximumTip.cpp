/*
Rahul and Ankit are the only two waiters in Royal Restaurant. Today, the restaurant received N orders. The amount of tips may differ when handled by different waiters, if Rahul takes the ith order, he would be tipped Ai rupees and if Ankit takes this order, the tip would be Bi rupees.
In order to maximize the total tip value they decided to distribute the order among themselves. One order will be handled by one person only. Also, due to time constraints Rahul cannot take more than X orders and Ankit cannot take more than Y orders. It is guaranteed that X + Y is greater than or equal to N, which means that all the orders can be handled by either Rahul or Ankit. Find out the maximum possible amount of total tip money after processing all the orders.

Input:

•    The first line contains one integer, number of test cases.
•    The second line contains three integers N, X, Y.
•    The third line contains N integers. The ith integer represents Ai.
•    The fourth line contains N integers. The ith integer represents Bi.

Output:
Print a single integer representing the maximum tip money they would receive.
 
Constraints:
1 ≤ N ≤ 105
1 ≤ X, Y ≤ N; X + Y ≥ N
1 ≤ Ai, Bi ≤ 104

 

Example:

Input:

2
5 3 3
1 2 3 4 5
5 4 3 2 1
8 4 4
1 4 3 2 7 5 9 6 
1 2 3 6 5 4 9 8

Output:
21
43
*/
#include <bits/stdc++.h>
using namespace std;

struct tip
{
    int absval;
    int index;
};
bool comparator(struct tip t1, struct tip t2)
{
    return (t1.absval > t2.absval);
}

int maxtip(int a[], int b[], int n, int x, int y)
{
    struct tip c[n];
    for (int i = 0; i < n; i++)
    {
        int k = abs(a[i] - b[i]);
        c[i].absval = k;
        c[i].index = i;
    }
    sort(c, c + n, comparator);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[c[i].index] > b[c[i].index])
        {
            if (x > 0)
            {
                sum += a[c[i].index];
                x--;
            }
            else
            {
                sum += b[c[i].index];
                y--;
            }
        }
        else
        {
            if (y > 0)
            {
                sum += b[c[i].index];
                y--;
            }
            else
            {
                sum += a[c[i].index];
                x--;
            }
        }
    }
    return sum;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n];
        int b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int total = maxtip(a, b, n, x, y);
        cout << total << endl;
    }
    return 0;
}