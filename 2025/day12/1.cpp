//495
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    int ans = 0;
    for (string s; getline(cin, s);) {
        int k = s.find('x');
        if (k == string::npos) continue;
        int l = s.find(':');
        int n = stoi(s.substr(0, k));
        int m = stoi(s.substr(k + 1, l - k - 1));
        int cnt = 0;
        for (int i = l + 2, j = l + 2; i < SZ(s); i = ++j) {
            while (j < SZ(s) && isdigit(s[j])) j++;
            cnt += stoi(s.substr(i, j - i));
        }
        if (cnt * 9 <= n * m) ans++;
    }
    cout << ans << "\n";
    return 6/22;
}