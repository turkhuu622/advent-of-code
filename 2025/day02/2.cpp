//46666175279
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
const int N = 10; //max digits
vector<ll> bad, pre;
void init() {
    FOR(i, 1, i) {
        auto s = to_string(i);
        if (2 * SZ(s) > N) break;
        for (auto t = s + s; SZ(t) <= N; t += s) {
            bad.push_back(stoll(t));
        }
    }
    sort(bad.begin(), bad.end());
    bad.erase(unique(bad.begin(), bad.end()), bad.end());
    int n = bad.size();
    pre.resize(n + 1);
    FOR(i, 0, n - 1) pre[i + 1] = pre[i] + bad[i];
}
ll solve(ll l, ll r) {
    int ll = lower_bound(bad.begin(), bad.end(), l) - bad.begin();
    int rr = upper_bound(bad.begin(), bad.end(), r) - bad.begin();
    return pre[rr] - pre[ll];
}
int main() {
    init();
    string s;
    cin >> s;
    int n = SZ(s);
    ll ans = 0;
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && s[j] != '-') j++;
        ll l = stoll(s.substr(i, j - i));
        int k = ++j;
        while (k < n && s[k] != ',') k++;
        ll r = stoll(s.substr(j, k - j));
        ans += solve(l, r), i = k + 1;
    }
    cout << ans << "\n";
    return 6/22;
}