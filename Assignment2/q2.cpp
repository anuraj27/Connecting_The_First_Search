#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ff first
#define ss second
#define pb push_back
#define int long long
#define double long double
#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vpii vector<pii>
#define pii pair<int, int>
#define Size(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define ffor(i, a, n) for (int i = a; i < n; i++)
#define rfor(i, a, n) for (int i = n - 1; i >= a; i--)
#define pinf 1e18
#define ninf -1e18
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
string yon[] = {"NO", "YES"};
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using muloset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 100005;
const int mod = 1000000007;

vb vis(MAXN), vis1(MAXN);
vvi adj(MAXN), adj1(MAXN);
vi res(MAXN), par(MAXN);

template <class T>
void scan(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];
}
template <class T>
void print(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void dfs1(int x)
{
    vis1[x] = true;
    for (auto i : adj1[x])
    {
        if (!vis1[i])
            dfs1(i);
    }
}

void dfs(int x, int n)
{
    vis[x] = true;
    if (x == n)
    {
        res[x] = 1;
        return;
    }
    for (auto i : adj[x])
    {
        if (!vis[i])
            dfs(i, n);
        if (vis1[i] && res[x] < res[i] + 1)
        {
            par[x] = i;
            res[x] = max(res[x], res[i] + 1);
        }
    }
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    auto start = std::chrono::high_resolution_clock::now();

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #" t ": ";
        int n, m;
        cin >> n >> m;
        ffor(i, 0, m)
        {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj1[v].pb(u);
        }

        dfs1(n);

        dfs(1, n);
        if (!vis[n])
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        int temp = 1;
        cout << res[1] << "\n";
        while (temp != 0)
        {
            cout << temp << " ";
            temp = par[temp];
        }
        cout << "\n";
    }

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((double)duration.count()) / ((double)1e9) << "s " << endl;

    return 0;
}