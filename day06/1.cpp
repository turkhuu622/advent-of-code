//5782351442566
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    vector<vector<ll>> a;
    ll ans = 0;
    for (string s; getline(cin, s);) {
        if (isdigit(s[0])) {
            vector<ll> b;
            for (int i = 0; i < SZ(s); i++) {
                if (s[i] == ' ') continue;
                int j = find(s.begin() + i, s.end(), ' ') - s.begin();
                b.push_back(stoll(s.substr(i, j - i)));
                i = j;
            }
            a.push_back(b);
        } else {
            for (int i = 0, j = 0; i < SZ(s); i++) {
                if (s[i] == ' ') continue;
                ll x = s[i] == '+' ? 0 : 1;
                for (auto b : a) s[i] == '+' ? x += b[j] : x *= b[j];
                j++;
                ans += x;
            }
        }
    }
    cout << ans << "\n";
    return 6/22;
}