//1141
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
        p = ((p + x * (s[0] == 'L' ? -1 : 1)) % 100 + 100) % 100;
        if (p == 0) ans++;
    }
    cout << ans << "\n";
    return 6/22;
}