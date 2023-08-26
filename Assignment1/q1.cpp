#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 100005;
const int mod = 1000000007;

vector<bool> visited(MAXN);
vector<vector<int>> adj(MAXN);
vector<int> tin(MAXN), tout(MAXN);
vector<pair<int, int>> back_edge;
int tym = 0;

void dfs(int ch, int p)
{
    visited[ch] = true;
    tin[ch] = tym++; // entry time.
    for (auto i : adj[ch])
    {
        if (i == p)
            continue;
        if (visited[i]) // back edge found.
        {
            back_edge.push_back({i, ch});
            back_edge.push_back({ch, i});
            continue;
        }
        dfs(i, ch);
    }
    tout[ch] = tym++; // exit time.
}

// check if there is any edge between u and v.
bool is_edge(int u, int v)
{
    bool ret = false;
    for (auto i : adj[v])
        ret |= (i == u);
    return ret;
}

// check which type of edge is between u and v.
void check(int u, int v)
{
    pair<int, int> temp = {u, v};
    if (!is_edge(u, v))
    {
        cout << "NO edge between u and v.\n";
        return;
    }
    for (auto i : back_edge)
    {
        if (i == temp)
        {
            cout << "Back edge.\n";
            return;
        }
    }
    cout << "Tree edge.\n";
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

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(i, 0);
    }

    int u, v;
    cin >> u >> v;
    check(u, v);

    return 0;
}