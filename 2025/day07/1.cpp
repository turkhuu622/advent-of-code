//1587
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    vector<string> a;
    for (string s; getline(cin, s); a.push_back(s));
    queue<array<int, 2>> q;
    FOR(i, 0, i) if (a[0][i] == 'S') {q.push({0, i}); break;}
    int n = SZ(a), ans = 0;
    auto add = [&](int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= SZ(a[x]) || a[x][y] != '.') return;
        a[x][y] = '|', q.push({x, y});
    };
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if (x == n - 1) continue;
        if (a[x + 1][y] == '^') {
            ans++;
            add(x + 1, y - 1);
            add(x + 1, y + 1);
        } else add(x + 1, y);
    }
    cout << ans << "\n";
    return 6/22;
}