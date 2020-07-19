/* Given a snake and ladder board of order 5x6, find the minimum number of dice throws required to reach the destination or last cell (30th cell) from source (1st cell) . 

Example
​For the above board output will be 3 
For 1st throw get a 2
For 2nd throw get a 6
For 3rd throw get a 2

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines. The first line of input contains an integer N denoting the no of ladders and snakes present. Then in the next line are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which takes to a position 'b'.

Output:
For each test case in a new line print the required answer denoting the min no of dice throws.

Constraints:
1 <= T <= 100
1 <= N <= 10
1 <= a <= 30
1 <= b <= 30

Example:
Input:
2
6
11 26 3 22 5 8 20 29 27 1 21 9
1
2 30

Output:
3
1

Explanation:
Testcase 1:
For 1st throw get a 2, which contains ladder to reach 22
For 2nd throw get a 6, which will lead to 28
Finally get a 2, to reach at the end 30. Thus 3 dice throws required to reach 30.
*/

#include <iostream>
#include <queue>
using namespace std;
bool inrange(int i, int n, bool *visited)
{
    return (i <= n && !visited[i]);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *ladderboard = new int[31];
        for (int i = 1; i <= 30; i++)
            ladderboard[i] = -1;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            ladderboard[a] = b;
        }
        n = 30;
        // linear ladderboard is ready
        // make a visited array
        bool *visited = new bool[n + 1];
        for (int i = 1; i <= n; i++)
            visited[i] = false;

        // now we will take a queue and we will store the value
        //(where we go) and the moves to reach that node
        queue<pair<int, int>> q;
        q.push({1, 0}); // means we are at position 1
                        // we have taken 0 steps till now
        // we are required to reach at position 36
        visited[1] = true;
        int ans = -1;
        bool found = false;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            if (front.first == n)
            {
                ans = front.second;
                found = true;
                break;
            }
            for (int j = front.first + 1; j <= front.first + 6; j++)
            {
                if (inrange(j, n, visited))
                {
                    if (ladderboard[j] == -1)
                    {
                        q.push({j, front.second + 1});
                        visited[j] = true;
                    }
                    else
                    {
                        q.push({ladderboard[j], front.second + 1});
                        visited[j] = true;
                    }
                }
            }
            if (found)
                break;
        }
        cout << ans << endl;
    }
}