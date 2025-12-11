//417190406827152
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    map<string, vector<string>> adj;
    map<string, int> in;
    for (string s; getline(cin, s);) {
        string x = s.substr(0, s.find(':'));
        vector<string> a;
        for (int i = s.find(' ') + 1, j = i; i < SZ(s); i = ++j) {
            while (j < SZ(s) && isalpha(s[j])) j++;
            string y = s.substr(i, j - i);
            in[y]++;
            a.push_back(y);
        }
        adj[x] = a;
    }
    map<string, array<ll, 4>> dp;
    queue<string> q;
    for (auto [s, a] : adj) if (in.find(s) == in.end()) q.push(s);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        if (x == "svr") dp[x][0] = 1;
        else if (x == "out") {cout << dp[x][3] << "\n"; return 0;}
        for (auto y : adj[x]) {
            FOR(i, 0, 3) {
                int ni = i;
                if (y == "dac") ni |= 1;
                if (y == "fft") ni |= 2;
                dp[y][ni] += dp[x][i];
            }
            if (!--in[y]) q.push(y);
        }
    }
    return 6/22;
}