//4759930955
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    vector<array<int, 2>> a;
    for (string s; getline(cin, s);) {
        int k = s.find(',');
        int x = stoi(s.substr(0, k));
        int y = stoi(s.substr(k + 1));
        a.push_back({x, y});
    }
    int n = SZ(a);
    ll ans = 0;
    FOR(i, 0, n - 1) {
        auto [xi, yi] = a[i];
        FOR(j, i + 1, n - 1) {
            auto [xj, yj] = a[j];
            ans = max(ans, (ll)abs(xi - xj + 1) * abs(yi - yj + 1));
        }
    }
    cout << ans << "\n";
    return 6/22;
}