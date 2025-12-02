//6634
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    int p = 50, ans = 0;
    for (string s; getline(cin, s);) {
        int x = stoi(s.substr(1));
        ans += x / 100, x %= 100;
        if (s[0] == 'L') {
            ans += p > 0 && p - x <= 0;
            p = (p - x + 100) % 100;
        } else {
            ans += p > 0 && p + x >= 100;
            p = (p + x) % 100;
        }

    }
    cout << ans << "\n";
    return 6/22;
}