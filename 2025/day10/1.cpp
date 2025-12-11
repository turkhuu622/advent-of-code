//479
#include <bits/stdc++.h>
#define FOR(i, a, b) for (auto i = (a); i <= (b); i++)
#define ROF(i, a, b) for (auto i = (a); i >= (b); i--)
#define SZ(a) int((a).size())
using namespace std;
using ll = long long;
int main() {
    int ans = 0;
    for (string s; getline(cin, s);) {
        string lights = s.substr(1, s.find(']') - 1);
        vector<int> buttons;
        for (int i = 0; (i = s.find('(', i) + 1) != 0;) {
            int button = 0;
            for (int j = i; isdigit(s[i]); i = ++j) {
                while (isdigit(s[j])) j++;
                button += 1 << stoi(s.substr(i, j - i));
            }
            buttons.push_back(button);
        }
        int n = SZ(lights);
        vector<int> dis(1 << n, -1);
        queue<int> q;
        dis[0] = 0, q.push(0);
        while (!q.empty()) {
            int mask = q.front();
            q.pop();
            for (int button : buttons) {
                int nmask = mask ^ button;
                if (dis[nmask] == -1) {
                    dis[nmask] = dis[mask] + 1;
                    q.push(nmask);
                }
            }
        }
        int lights_mask = 0;
        FOR(i, 0, n - 1) if (lights[i] == '#') lights_mask += 1 << i;
        ans += dis[lights_mask];
    }
    cout << ans << "\n";
    return 6/22;
}