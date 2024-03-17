#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval)
{
    vector<vector<int>> ans;
    int n = intervals.size();
    if (n == 0)
    {
        ans.push_back(newInterval);
        return ans;
    }
    int i = 0;
    // case 1: no overlapping case before the merge intervals
    // compare ending point of intervals to starting point of newInterval
    while (i < n && intervals[i][1] < newInterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }
    // case 2: overlapping case and merging of intervals
    while (i < n && newInterval[1] >= intervals[i][0])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);
    // case 3: no overlapping of intervals after newinterval being merged
    while (i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "[" << v[i][0] << "," << v[i][1] << "]" << endl;
    }
    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];
    cout << "[" << newInterval[0] << "," << newInterval[1] << "]" << endl;

    vector<vector<int>> ans = insert(v, newInterval);
    int curr_size = ans.size();
    for (int i = 0; i < curr_size; i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 0; it < t; it++)
    {
        cout << "Case #" << it + 1 << ": ";
        solve();
    }
    return 0;
}
