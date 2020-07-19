/* Given a chess board of order N x M and source points (s1, s2) and destination points (d1, d2). The task to find minimum number of moves required by the Knight to go to the destination cell.
Note: The chess board consists of rows numbered (1 to N) and columns (1 to M).

Input:
The first line of input contains an integer T denoting the number of testcases. Then T test cases follow. Each test case contains two lines. The first line of each testcase contains two space separated integers N and M. Then in the next line are four space separated values s1, s2 and d1, d2.

Output:
For each testcase in a new line print the minimum number of moves required by the knight to go to the destination from the source. If no such move is possible print -1.

Constraints:
1 <= T <= 100
1 <= N, M <= 25

Example:
Input:
2
4 7
2 6 2 4
7 13
2 8 3 4

Output:
2
3

Explanation:
Testcase 1: One possible move for Knight is from 2, 6 to 4, 5 and then to 2, 4 which is our destination.]
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct entry
{
    int x;
    int y;
    int dist;
    entry() {}
    entry(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool inrange(int x, int y, int A, int B)
{
    if (x >= 0 && x < A && y >= 0 && y < B)
    {
        return true;
    }
    return false;
}

int stepsKnight(int A, int B, int C, int D, int E, int F)
{
    queue<entry> q;
    int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
    int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};
    entry start(C - 1, D - 1, 0);
    vector<vector<bool>> visited(A, vector<bool>(B, false));
    visited[C - 1][D - 1] = true;
    q.push(start);
    int x, y, dist;
    while (!q.empty())
    {
        entry e = q.front();
        q.pop();
        if (e.x == E - 1 && e.y == F - 1)
        {
            return e.dist;
        }

        for (int i = 0; i < 8; i++)
        {
            x = e.x + dx[i];
            y = e.y + dy[i];
            if (inrange(x, y, A, B) && !visited[x][y])
            {
                visited[x][y] = true;
                entry n(x, y, e.dist + 1);
                q.push(n);
            }
        }
    }
    return -1;
}

int main()
{
    //code
    int t;
    cin >> t;

    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int C, D, E, F;
        cin >> C >> D >> E >> F;
        int steps = stepsKnight(N, M, C, D, E, F);
        cout << steps << endl;
    }
    return 0;
}