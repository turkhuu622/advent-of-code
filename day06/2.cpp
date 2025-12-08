//10194584711842
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    vector<string> a;
    for (string s; getline(cin, s);) {
        if (s[0] != '+' && s[0] != '*') {
            a.push_back(s);
        } else {
            ll ans = 0;
            for (int i = 0, j = 0; i < SZ(s); i = j) {
                for (j++; j < SZ(s) && s[j] == ' '; j++);
                ll x = s[i] == '+' ? 0 : 1;
                ROF(k, j == SZ(s) ? j - 1 : j - 2, i) {
                    ll y = 0;
                    for (auto t : a) if (t[k] != ' ') y = y * 10 + t[k] - '0';
                    s[i] == '+' ? x += y : x *= y;
                }
                ans += x;
            }
            cout << ans << "\n";
        }
    }
    return 6/22;
}