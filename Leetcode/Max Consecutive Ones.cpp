/*
Link : https://leetcode.com/problems/max-consecutive-ones/description/
Approach : Sliding window
window will start when it encounters 1 , and wiil end when it encounters 0
*/
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

int findMaxConsecutiveOnes(vector<int> &nums)
{

    // 1 1 0 0 1 1 1 0 1 1 1 1

    int n = nums.size();
    if (n < 0)
    {
        return 0;
    }

    int l = 0, r = 0;
    int maxLength = 0;
    while (l <= r && r < n)
    {
        if (nums[l] == 1)
        {

            while (r < n && nums[r] == 1)
            {

                r++;
            }
            // cout << "l: " << l << " r: " << r << endl;
            int currLength = r - l;
            maxLength = max(maxLength, currLength);
            cout << "maxLength: " << maxLength << endl;
            l = r;
        }
        else
        {

            l++;
            r++;
        }
    }
    return maxLength;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << findMaxConsecutiveOnes(nums) << endl;
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