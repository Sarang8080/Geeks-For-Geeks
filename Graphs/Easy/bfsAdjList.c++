#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfs(vector<int> g[], int N)
{
    int visited[N] = {0};
    vector<int> ans;
    queue<int> q;
    int i = 0;
    if (visited[i] == 0)
    {
        ans.push_back(i);
        visited[i] = 1;
        q.push(i);
    }
    while (!q.empty())
    {
        i = q.front();
        q.pop();
        if (visited[i] == 0)
        {
            ans.push_back(i);
            visited[i] = 1;
        }
        for (auto j : g[i])
        {
            if (!visited[i])
            {
                q.push(i);
            }
        }
    }
    return ans;
}