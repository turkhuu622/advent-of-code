//5748679033029
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    vector<string> a;
    for (string s; getline(cin, s); a.push_back(s));
    int n = SZ(a), m = SZ(a[0]);
    vector dp(n, vector<ll>(m));
    queue<array<int, 2>> q;
    FOR(i, 0, i) if (a[0][i] == 'S') {q.push({0, i}); dp[0][i] = 1; break;}
    auto add = [&](int px, int py, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) return;
        if (a[x][y] != '^') dp[x][y] += dp[px][py];
        if (a[x][y] == '.') a[x][y] = '|', q.push({x, y});
    };
    ll ans = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n - 1) {ans += dp[x][y]; continue;}
        if (a[x + 1][y] == '^') {
            add(x, y, x + 1, y - 1);
            add(x, y, x + 1, y + 1);
        } else add(x, y, x + 1, y);
    }
    cout << ans << "\n";
    return 6/22;
}