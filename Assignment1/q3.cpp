#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;
const int mod = 1000000007;

vector<int> id(MAXN);
vector<bool> visited(MAXN);
vector<vector<int>> adj(MAXN);

void dfs(int x, int y)
{
    visited[x] = true;
    id[x] = y;
    for (auto i : adj[x])
    {
        if (!visited[i])
            dfs(i, y);
    }
}

void connected_component_dfs(int n)
{
    int x = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, x), x++;
    }
}

void bfs(int x, int y)
{
    queue<int> q;
    q.push(x);
    id[x] = y;
    visited[x] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto i : adj[temp])
        {
            if (!visited[i])
            {
                q.push(i);
                id[x] = y;
                visited[i] = true;
            }
        }
    }
}

void connected_component_bfs(int n)
{
    int x = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            bfs(i, x), x++;
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    connected_component_dfs(n);
    connected_component_bfs(n);

    return 0;
}