//16927
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    int ans = 0;
    for (string s; getline(cin, s);) {
        int max_j = 0, max_d = s.back() - '0';
        ROF(i, SZ(s) - 2, 0) {
            int d = s[i] - '0';
            max_j = max(max_j, d * 10 + max_d);
            max_d = max(max_d, d);
        }
        ans += max_j;
    }
    cout << ans << "\n";
    return 6/22;
}