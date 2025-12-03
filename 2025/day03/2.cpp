//167384358365132
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    ll ans = 0;
    for (string s; getline(cin, s);) {
        vector<ll> dp(13, -1e17);
        dp[0] = 0;
        for (char c : s) ROF(i, 12, 1) dp[i] = max(dp[i], dp[i - 1] * 10 + c - '0');
        ans += dp[12];
    }
    cout << ans << "\n";
    return 6/22;
}