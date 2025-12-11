//643
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
    map<string, ll> dp;
    queue<string> q;
    for (auto [s, a] : adj) if (in.find(s) == in.end()) q.push(s);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        if (x == "you") dp[x] = 1;
        else if (x == "out") {cout << dp[x] << "\n"; return 0;}
        for (auto y : adj[x]) {
            dp[y] += dp[x];
            if (!--in[y]) q.push(y);
        }
    }
    return 6/22;
}