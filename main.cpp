#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
// #define ll long long
#define pb push_back
#define ff first
#define ss second
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define Yes cout << "Yes\n";
#define No cout << "No\n";
#define CC(x) cout << "Case " << ++x << ": ";
#define CS(x) cout << "Case #" << ++x << ": ";
#define endl "\n"
const double pi = acos(-1);
#define rep(i, a, n) for (int i = a; i < n; i++)
const int MOD = 1e9 + 7, N = 2e5 + 5;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define order_set tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

int binpow(int a, int b)
{
    if (b == 0)
        return 1;
    int res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

// bool palindrome(int x)
// {
//     string s = to_string(x);
//     int n = s.size();
//     for (int i = 0; i < n / 2; i++)
//     {
//         if (s[i] != s[n - i - 1])
//             return false;
//     }
//     return true;
// }

bool prime(int n)
{
    int flag = 0;
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

bool isPrime[N];
vector<int> primes;
void sieve()
{
    for (int i = 2; i < N; i++)
        isPrime[i] = 1;

    for (int i = 2; i * i < N; i++)
        if (isPrime[i])
            for (int j = i * i; j < N; j += i)
                isPrime[j] = 0;

    for (int i = 2; i < N; i++)
        if (isPrime[i])
            primes.push_back(i);
}

int spf[N];
void smallPrimeFactorization()
{
    for (int i = 2; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++)
        if (spf[i] == i)
            for (int j = i * i; j < N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

int sToi(string s)
{
    int val = 0, cnt = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--)
    {
        val += (s[i] - '0') * binpow(10, cnt);
        cnt++;
    }
    return val;
}

int dec2bin(int n)
{
    vector<int> bin;
    while (n > 0)
    {
        if (n & 1)
            bin.push_back(1);
        else
            bin.push_back(0);
        n /= 2;
    }

    reverse(bin.begin(), bin.end());
    int val = 0;

    rep(i, 0, bin.size())
    {
        val += bin[i] * binpow(2, i);
    }

    return val;
}

void solve(int tc, int t)
{
    char x, y;
    cin >> x >> y;
    int a = x - 32, b = y - 32;
    for (int i = 1; i <= 94; i++)
    {
        if (a % i == b % i)
        {
            int xx = ceil(1.0 * 94 / i);
            cout << i << " " << xx << endl;
        }
    }
    cout << endl;
}

signed main()
{
    fast;

    // sieve();
    // smallPrimeFactorization();
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        solve(tc, t);
    }

    return 0; // It's Sabbir
}
