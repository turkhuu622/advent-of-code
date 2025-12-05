//1424
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    vector<string> g;
    for (string s; getline(cin, s); g.push_back(s));
    int n = g.size(), m = g[0].size(), ans = 0;
    FOR(i, 0, n - 1) FOR(j, 0, m - 1) if (g[i][j] == '@') {
        int cnt = 0;
        FOR(x, i - 1, i + 1) FOR(y, j - 1, j + 1) {
            if (x == i && y == j) continue;
            if (x < 0 || x >= n) continue;
            if (y < 0 || y >= m) continue;
            if (g[x][y] == '@') cnt++;
        }
        if (cnt < 4) ans++;
    }
    cout << ans << "\n";
    return 6/22;
}
