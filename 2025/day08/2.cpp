//36045012
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
ll sq(int x) {
    return (ll)x * x;
}
int main() {
    vector<array<int, 3>> c;
    for (string s; getline(cin, s);) {
        int i = s.find(','), j = s.find(',', i + 1);
        int x = stoi(s.substr(0, i));
        int y = stoi(s.substr(i + 1, j - i - 1));
        int z = stoi(s.substr(j + 1));
        c.push_back({x, y, z});
    }
    auto distdist = [&](int i, int j) {
        auto [xi, yi, zi] = c[i];
        auto [xj, yj, zj] = c[j];
        return sq(xi - xj) + sq(yi - yj) + sq(zi - zj);
    };
    int n = SZ(c);
    vector<array<int, 2>> edges;
    FOR(i, 0, n - 1) FOR(j, i + 1, n - 1) edges.push_back({i, j});
    sort(edges.begin(), edges.end(), [&](auto e1, auto e2) {
        return distdist(e1[0], e1[1]) < distdist(e2[0], e2[1]);
    });
    vector<int> p(n), sz(n, 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](this auto find, int x) -> int {
        return p[x] == x ? x : p[x] = find(p[x]);
    };
    ll ans = 0;
    FOR(i, 0, i) {
        auto [_x, _y] = edges[i];
        if (int x, y; (x = find(_x)) != (y = find(_y))) {
            ans = (ll)c[_x][0] * c[_y][0];
            p[x] = y, sz[y] += sz[x];
            if (sz[y] == n) break;
        }
    }
    cout << ans << "\n";
    return 6/22;
}