#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;
const int mod = 1000000007;

vector<bool> visited(MAXN);
vector<int> dst(MAXN, INT_MAX);
vector<vector<int>> adj(MAXN);

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dst[src] = 0;
    visited[src] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto i : adj[temp])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
                dst[i] = dst[temp] + 1;
            }
        }
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

    int src;
    cin >> src;
    bfs(src);

    return 0;
}