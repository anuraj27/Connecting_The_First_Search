#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;
const int mod = 1000000007;

vector<bool> visited(MAXN);
vector<vector<int>> adj(MAXN);

bool dfs(int x)
{
    visited[x] = true;
    for (auto i : adj[x])
    {
        if (visited[i])
            return true;
        if (!visited[i] && dfs(i))
            return true;
    }
    return false;
}

bool is_cycle_dfs(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i))
            return true;
    }
    return false;
}

bool bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto i : adj[temp])
        {
            if (visited[i])
                return true;
            q.push(i);
            visited[i] = true;
        }
    }
    return false;
}

bool is_cycle_bfs(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && bfs(i))
            return true;
    }
    return false;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}