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

// Topological sorting with BFS approach
bool canFinish(int numCourse, vector<vector<int>> &prerequisites)
{
    // 1. build graph
    // 2. track indegrees
    // 3. push into queue for vertices having indegree = 0
    // 4. remove each vertex from queue and decrement indegree of those vertices having edges with that vertex
    // 5. if no of visited vertices is not equal to numCourse , then a cycle exists else no cycle

    unordered_map<int, vector<int>> graph;
    vector<int> indegree(numCourse);
    int n = prerequisites.size();
    for (int i = 0; i < n; i++)
    {
        graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        indegree[prerequisites[i][1]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourse; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    int visited = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        visited++;
        for (auto it = graph[node].begin(); it != graph[node].end(); it++)
        {
            indegree[*it]--;
            if (indegree[*it] == 0)
            {
                q.push(*it);
            }
        }
    }

    if (visited != numCourse)
    {
        return false;
    }
    return true;
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 0; it < t; it++)
    {
        cout << "Case #" << it + 1 << ": ";
        int numCourse;
        cin >> numCourse;
        int m;
        cin >> m;
        vector<vector<int>> prerequisites(m, vector<int>(2));
        for (int i = 0; i < m; i++)
        {
            cin >> prerequisites[i][0] >> prerequisites[i][1];
        }
        cout<<canFinish(numCourse, prerequisites)<<endl;
    }
    return 0;
}
