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

const int MAXN = 200005;
const int mod = 1000000007;

vi fw(MAXN);

template <class T>
void scan(vector<T> &v)
{
    for (int i = 1; i < v.size(); i++)
        cin >> v[i];
}
template <class T>
void print(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void update(int idx, int n, int val)
{
    for (; idx <= n; idx += idx & -idx)
        fw[idx] += val;
}

int query(int idx)
{
    int ret = 0;
    for (; idx > 0; idx -= idx & -idx)
        ret += fw[idx];
    return ret;
}

int32_t main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case #" t ": ";
        int n, q;
        cin >> n >> q;
        vi v(n + 1);
        scan(v);
        while (q--)
        {
            int x, y, z, w;
            cin >> x;
            if (x == 1)
            {
                cin >> y >> z >> w;
                update(y, n, w);
                update(z + 1, n, -w);
            }
            else
            {
                cin >> y;
                cout << (v[y] + query(y)) << "\n";
            }
        }
    }
    return 0;
}