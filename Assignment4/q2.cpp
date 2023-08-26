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
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
string yon[] = {"NO", "YES"};
template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using muloset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*      -------------------------DEBUGGING----------------------------       */
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif
void __print(int x)
{
    cerr << x;
}
void __print(char x) { cerr << x; }
void __print(bool x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(string x) { cerr << x; }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

const int MAXN = 100005;
const int mod = 1000000007;

vi dst(MAXN, 1000000000000000), res(MAXN), v1(MAXN, INT_MAX), v2(MAXN);
vb vis1(MAXN), vis2(MAXN), vis3(MAXN);
vector<vector<pair<int, int>>> adj(MAXN), adj1(MAXN);

void dijkstra(int src)
{
    dst[src] = 0;
    priority_queue<pii, vpii, greater<pii>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        if (vis1[temp.ss])
            continue;
        vis1[temp.ss] = true;
        for (auto i : adj1[temp.ss])
        {
            if (!vis1[i.ff] && dst[i.ff] > dst[temp.ss] + i.ss)
            {
                dst[i.ff] = dst[temp.ss] + i.ss;
                pq.push({dst[i.ff], i.ff});
            }
        }
    }
}

void dfs1(int x, int y, int n)
{
    vis2[x] = true;
    if (x == n)
    {
        v1[x] = v2[x] = 0;
        res[n] = 1;
        return;
    }
    for (auto i : adj[x])
    {
        if (dst[i.ff] + i.ss == y)
        {
            if (!vis2[i.ff])
                dfs1(i.ff, y - i.ss, n);
            v1[x] = min(v1[x], v1[i.ff] + 1);
            v2[x] = max(v2[x], v2[i.ff] + 1);
            res[x] = (res[x] + res[i.ff]) % mod;
        }
    }
    return;
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
        // cout << "Case #" << t << ": ";
        int n, m;
        cin >> n >> m;
        ffor(i, 0, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb({v, w});
            adj1[v].pb({u, w});
        }

        dijkstra(n);
        dfs1(1, dst[1], n);

        cout << dst[1] << " " << res[1] << " " << v1[1] << " " << v2[1] << "\n";
    }

    cout << fixed << setprecision(8);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((double)duration.count()) / ((double)1e9) << "s " << endl;

    return 0;
}