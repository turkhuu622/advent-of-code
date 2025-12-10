//1525241870
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    vector<array<int, 2>> a;
    vector<int> v[2];
    for (string s; getline(cin, s);) {
        int k = s.find(',');
        int x = stoi(s.substr(0, k));
        int y = stoi(s.substr(k + 1));
        a.push_back({x, y});
        FOR(i, 0, 1) v[i].push_back(a.back()[i]);
    }
    for (auto& u : v) {
        sort(u.begin(), u.end());
        u.erase(unique(u.begin(), u.end()), u.end());
    }
    int n = SZ(v[0]) + 2, m = SZ(v[1]) + 2;
    for (auto& p : a) FOR(i, 0, 1) {
        p[i] = lower_bound(v[i].begin(), v[i].end(), p[i]) - v[i].begin() + 1;
    }
    vector sout(n, vector<bool>(m));
    FOR(i, 0, SZ(a) - 1) {
        auto [px, py] = a[i];
        auto [nx, ny] = a[(i + 1) % SZ(a)];
        FOR(x, min(px, nx), max(px, nx)) {
            FOR(y, min(py, ny), max(py, ny)) {
                sout[x][y] = 1;
            }
        }
    }
    /* fill */ {
        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};
        auto is_in = [&](int x, int y) {
            return 0 <= x && x < n && 0 <= y && y < m;
        };
        vector vis(n, vector<bool>(m));
        queue<array<int, 2>> q;
        // (0,0) is outside
        vis[0][0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            FOR(d, 0, 3) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (is_in(nx, ny) && !sout[nx][ny] && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        auto fill = [&](this auto fill, int x, int y) -> void {
            sout[x][y] = 1;
            FOR(d, 0, 3) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (is_in(nx, ny) && !sout[nx][ny]) fill(nx, ny);
            }
        };
        FOR(i, 0, n - 1) FOR(j, 0, m - 1) {
            if (!sout[i][j] && !vis[i][j]) {
                // (i,j) is inside
                fill(i, j);
            }
        }
    }
    vector ps(n, vector<int>(m));
    FOR(i, 1, n - 1) {
        FOR(j, 1, m - 1) {
            ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1] + sout[i][j];
        }
    }
    ll ans = 0;
    FOR(i, 0, SZ(a) - 1) {
        FOR(j, i + 1, SZ(a) - 1) {
            auto [xlo, ylo] = a[i];
            auto [xhi, yhi] = a[j];
            if (xlo > xhi) swap(xlo, xhi);
            if (ylo > yhi) swap(ylo, yhi);
            int area = 0;
            area += ps[xhi][yhi];
            area -= ps[xhi][ylo - 1];
            area -= ps[xlo - 1][yhi];
            area += ps[xlo - 1][ylo - 1];
            if (area == (xhi - xlo + 1) * (yhi - ylo + 1)) {
                ans = max(ans, (ll)(v[0][xhi - 1] - v[0][xlo - 1] + 1) * (v[1][yhi - 1] - v[1][ylo - 1] + 1));
            }
        }
    }
    cout << ans << "\n";
    return 6/22;
}