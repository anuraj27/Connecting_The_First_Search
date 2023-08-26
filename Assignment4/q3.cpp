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
        vvi dp(n + 1, vi(n + 1, INT_MAX));
        ffor(i, 0, n + 1)
            dp[i][i] = 0;
        ffor(i, 0, m)
        {
            int u, v, w;
            cin >> u >> v >> w;
            dp[u][v] = dp[v][u] = w;
        }
        ffor(k, 1, n + 1)
        {
            ffor(i, 1, n + 1)
            {
                ffor(j, 1, n + 1)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }

        int u, v, x;
        cin >> u >> v >> x;
        dp[u][v] = x;
        // update dp array in O(V*V).
        ffor(i, 1, n + 1)
        {
            ffor(j, 1, n + 1)
            {
                dp[i][j] = min(dp[i][j], dp[i][u] + dp[u][v] + dp[v][j]);
                dp[i][j] = min(dp[i][j], dp[i][v] + dp[u][v] + dp[u][j]);
            }
        }
    }

    cout << fixed << setprecision(8);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cerr << "Time taken : " << ((double)duration.count()) / ((double)1e9) << "s " << endl;

    return 0;
}