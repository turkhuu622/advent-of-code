//733
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    vector<array<ll, 2>> ranges;
    for (string s; getline(cin, s) && !s.empty();) {
        int k = s.find('-');
        ranges.push_back({stoll(s.substr(0, k)), stoll(s.substr(k + 1))});
    }
    int ans = 0;
    for (string s; getline(cin, s);) {
        ll x = stoll(s);
        bool fresh = 0;
        for (auto [l, r] : ranges) {
            if (l <= x && x <= r) fresh = 1;
        }
        if (fresh) ans++;
    }
    cout << ans << "\n";
    return 6/22;
}