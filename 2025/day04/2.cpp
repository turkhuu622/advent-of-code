//8727
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
    auto is_in = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };
    auto is_accessible = [&](int i, int j) {
        if (!is_in(i, j) || g[i][j] != '@') return false;
        int cnt = 0;
        FOR(x, i - 1, i + 1) FOR(y, j - 1, j + 1) {
            if (x == i && y == j) continue;
            if (is_in(x, y) && g[x][y] == '@') cnt++;
        }
        return cnt < 4;
    };
    queue<array<int, 2>> q;
    FOR(i, 0, n - 1) FOR(j, 0, m - 1) if (is_accessible(i, j)) g[i][j] = '.', q.push({i, j});
    for (; !q.empty(); ans++) {
        auto [x, y] = q.front();
        q.pop();
        FOR(nx, x - 1, x + 1) FOR(ny, y - 1, y + 1) if (is_accessible(nx, ny)) g[nx][ny] = '.', q.push({nx, ny});
    }
    cout << ans << "\n";
    return 6/22;
}