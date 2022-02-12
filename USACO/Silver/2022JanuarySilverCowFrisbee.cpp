#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int N;
vector<int> h(MAXN);

int main() {
    //freopen("input.in", "r", stdin);
    cin >> N;
    h.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> h[i];
    }

    vector<pair<int, int>> s;
    long long ans = 2 * (N - 1);
    for (int i = 0; i < N; ++i) {
        if (s.empty() || h[i] < s.back().first) {
            s.push_back({h[i], i});
        }
        else {
            while (!s.empty()) {
                if (h[i] > s.back().first) {
                    if (s.size() >= 2) {
                        ans += i - s[s.size() - 2].second + 1;
                    }
                    s.pop_back();
                }
                else {
                    break;
                }
            }
            s.push_back({h[i], i});
        }
    }

    cout << ans << '\n';

    return 0;
}
