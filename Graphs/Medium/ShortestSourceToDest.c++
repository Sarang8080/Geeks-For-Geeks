/*Given a boolean 2D matrix (0-based index), find whether there is path from (0,0) to (x,y) and if there is one path, print the minimum no of steps needed to reach it, else print -1 if the destination is not reachable. You may move in only four direction ie up, down, left and right. The path can only be created out of a cell if its value is 1.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two lines . The first line of each test case contains two integers n and m denoting the size of the matrix. Then in the next line are n*m space separated values of the matrix. The following line after it contains two integers x and y denoting the index of the destination.

Output:
For each test case print in a new line the min no of steps needed to reach the destination.

Constraints:
1<=T<=100
1<=n,m<=20

Example:
Input:
2
3 4
1 0 0 0 1 1 0 1 0 1 1 1
2 3
3 4
1 1 1 1 0 0 0 1 0 0 0 1
0 3
Output:
5
3
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct entry
{
    int x;
    int y;
    int steps;
    entry() {}
    entry(int x, int y, int steps) : x(x), y(y), steps(steps) {}
};
bool inrange(int x, int y, int A, int B)
{
    if (x >= 0 && x < A && y >= 0 && y < B)
    {
        return true;
    }
    return false;
}

int minSteps(vector<vector<int>> &mat, int A, int B, int C, int D, int E, int F)
{
    if (mat[0][0] == 0 || mat[E][F] == 0)
    {
        return -1;
    }
    queue<entry> q;
    entry start(C, D, 0);
    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};
    vector<vector<bool>> visited(A, vector<bool>(B, false));
    visited[C][D] = true;
    q.push(start);
    int x, y, steps;
    while (!q.empty())
    {
        entry e = q.front();
        q.pop();
        if (e.x == E && e.y == F)
        {
            return e.steps;
        }
        for (int i = 0; i < 4; i++)
        {
            x = e.x + dx[i];
            y = e.y + dy[i];
            if (inrange(x, y, A, B) && mat[x][y] == 1 && !visited[x][y])
            {
                visited[x][y] = true;
                entry n(x, y, e.steps + 1);
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
        int A, B;
        cin >> A >> B;
        vector<vector<int>> mat(A, vector<int>(B));
        for (int i = 0; i < A; i++)
        {
            for (int j = 0; j < B; j++)
            {
                cin >> mat[i][j];
            }
        }
        int E, F;
        cin >> E >> F;
        int steps = minSteps(mat, A, B, 0, 0, E, F);
        cout << steps << endl;
    }
    return 0;
}