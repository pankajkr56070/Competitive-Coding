/*
Leetcode link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

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

int maxProfit(vector<int> &prices)
{
    int n = sz(prices);
    if (n <= 1)
    {
        return 0;
    }
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int find(vector<int> &prices, vector<vector<vector<int>>> &dp, int index, int buy, int txn)
{
    if (txn >= 2)
    {
        return 0;
    }
    if (index >= sz(prices))
    {
        return 0;
    }
    if (dp[index][buy][txn] != -1)
    {
        // cout<<"index "<<index<<"buy "<<buy<<" :"<<dp[buy][index]<<endl;
        return dp[index][buy][txn];
    }
    // option of buying at current index
    if (buy == 0)
    {
        return dp[index][buy][txn] = max(-prices[index] + find(prices, dp, index + 1, 1, txn), find(prices, dp, index + 1, 0, txn));
    }
    else
    {
        // option of selling at current index
        return dp[index][buy][txn] = max(prices[index] + find(prices, dp, index + 1, 0, txn + 1), find(prices, dp, index + 1, 1, txn));
    }
}
int maxProfitWithMemoization(vector<int> &prices)
{
    int n = prices.size();
    if (n <= 1)
    {
        return 0;
    }
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
    // dp[0][0] = -prices[0];
    // dp[1][0] = 0;
    return find(prices, dp, 0, 0, 0);
    // return dp[1][n-1];
}

void solve()
{
    int n;
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    // cout<< maxProfit(prices)<<endl;
    cout << maxProfitWithMemoization(prices) << endl;
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
