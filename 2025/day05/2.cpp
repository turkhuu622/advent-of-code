//345821388687084
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
    for (string s; getline(cin, s););
    sort(ranges.begin(), ranges.end());
    ll ans = 0, lst = -1;
    for (auto [l, r] : ranges) {
        if (l > lst) ans += r - l + 1, lst = r;
        else if (r > lst) ans += r - lst, lst = r;
    }
    cout << ans << "\n";
    return 6/22;
}