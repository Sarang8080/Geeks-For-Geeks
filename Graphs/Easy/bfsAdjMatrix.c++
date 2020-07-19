#include <iostream>
#include <queue>
using namespace std;
#define MAX 51

void bfs(int A[][MAX], int i, int n)
{
    int u;
    int visited[MAX] = {0};
    visited[i] = 1;
    cout << i << " ";
    queue<int> q;
    q.push(i);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (A[u][v] == 1 && visited[v] == 0)
            {
                cout << v << " ";
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}