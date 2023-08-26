#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;
const int mod = 1000000007;

vector<bool> visited(MAXN);
vector<int> tin(MAXN), low(MAXN);
vector<vector<int>> adj(MAXN);
map<pair<int, int>, bool> bridge_edge;
int tym = 0;

void dfs(int ch, int p = 0)
{
    visited[ch] = true;
    tin[ch] = low[ch] = tym++;
    for (auto i : adj[ch])
    {
        if (i == p)
            continue;
        if (visited[i])
        {
            low[ch] = min(low[ch], tin[i]);
            continue;
        }
        dfs(i, ch);
        low[ch] = min(low[ch], low[i]);
        if (low[i] > tin[ch])
            bridge_edge[{i, ch}] = bridge_edge[{ch, i}] = true;
    }
}

void find_bridge(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i);
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

    find_bridge(n);

    return 0;
}