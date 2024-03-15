#include <iostream>
#include <vector>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second
#define mee cout << "me" \
                 << "\n";
#define all(x) x.begin(), x.end()
#define Ceil(x, y) ((x + y - 1) / y)
#define debug(x) cout << #x << " - " << x << "\n";
#define FLUSH ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define TIME cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#define bufpb cin.ignore(numeric_limits<streamsize> : : max(), '\n');

const int MOD = 1e9 + 7;

/*MATH utilities */
//----------------//
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

bool isPrime(ll n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

ll super_power(ll base, ll power)
{
    ll res = 1;
    while (power > 0)
    {
        if (power & 1)
            res = (res * base);
        power >>= 1;
        base = (base * base);
    }
    return res;
}
//----------------//

template <typename T>
void printVec(vector<T> v)
{
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}

int findMaxConsecutiveOnes(vector<int> &arr, int m)
{
    int n = arr.size();
    int wL = 0, wR = 0;

    // Left index and size of the widest window
    int bestL = 0, bestWindow = 0;

    // Count of zeroes in current window
    int zeroCount = 0;

    // While right boundary of current window doesn't cross
    // right end
    while (wR < n)
    {
        // If zero count of current window is less than m,
        // widen the window toward right
        if (zeroCount <= m)
        {
            if (arr[wR] == 0)
                zeroCount++;
            wR++;
        }

        // If zero count of current window is more than m,
        // reduce the window from left
        if (zeroCount > m)
        {
            if (arr[wL] == 0)
                zeroCount--;
            wL++;
        }

        // Update widest window if this window size is more
        if ((wR - wL > bestWindow) && (zeroCount <= m))
        {
            bestWindow = wR - wL;
            bestL = wL;
        }
    }
    return bestWindow;
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
    cout << findMaxConsecutiveOnes(v, 1) << endl;
}

int main()
{
    FLUSH
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}