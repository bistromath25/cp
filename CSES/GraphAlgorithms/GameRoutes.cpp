#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5, INF = 1e9, MOD = 1e9 + 7;
int N, M;
vector<int> gf[MAXN + 1], gr[MAXN + 1];
int indeg[MAXN + 1];
int dp[MAXN + 1];  // dp[i] = no. ways to reach i

int main() {
    //freopen("input.in", "r", stdin);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        indeg[i] = 0;
        dp[i] = 0;
    }

    for (int i = 1, a, b; i <= M; ++i) {
        cin >> a >> b;
        gf[a].push_back(b);
        gr[b].push_back(a);
        indeg[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }

    dp[1] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int &prv : gr[cur]) {
            dp[cur] += dp[prv];
            dp[cur] %= MOD;
        }

        for (int &nxt : gf[cur]) {
            indeg[nxt]--;
            if (indeg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
