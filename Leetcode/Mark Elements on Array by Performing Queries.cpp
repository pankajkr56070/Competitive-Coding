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

// Define a custom comparison function for pairs
static bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first) {
            return a.second > b.second; // Sort by second element if first elements are equal
        }
    return a.first > b.first; // Otherwise, sort by first element
}

vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int m = queries.size();

    vector<bool> marked(n, false);
    // marked[queries[0][0]] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> minHeap(&compare);

    for (int i = 0; i < n; i++)
    {
        if (i != queries[0][0])
        {
            minHeap.push({nums[i], i});
        }
    }

    long long int totalSum = accumulate(nums.begin(), nums.end(), 0);
    cout<<"Total sum "<<totalSum;
    vector<long long int> answer(m);
    for (int i = 0; i < m; i++)
    {
        long long int curr_sum = totalSum;
        if (marked[queries[i][0]] == false)
        {
            curr_sum -= nums[queries[i][0]];
            marked[queries[i][0]] = true;
        }
        int totalEle = queries[i][1];
        while (totalEle > 0 && !minHeap.empty())
        {
            int topEle = minHeap.top().first;
            int topIndex = minHeap.top().second;
            cout<<"Top element "<<topEle<<"top index "<<topIndex<<endl;
            if (marked[topIndex] == false)
            {
                minHeap.pop();
                curr_sum -= topEle;
                marked[topIndex] = true;
            }
            totalEle--;
        }
        cout<<"Curr sum "<<curr_sum<<endl;
        totalSum = curr_sum;
        answer[i] = totalSum;
    }
    return answer;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int m;
    cin >> m;
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<long long>  ans = unmarkedSumArray(v, queries);
    for(int i = 0 ; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
