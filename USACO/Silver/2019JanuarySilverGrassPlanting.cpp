#include <bits/stdc++.h>
using namespace std;

// number of colors required is somehow max degree of a vertex plus one
// determined this by drawing a bunch of example graphs

const int MAXN = 1e5 + 1;
int N;
vector<int> g[MAXN], deg(MAXN, 0);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    cin >> N;
    for (int i = 1, a, b; i <= N - 1; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    int maxdeg = 0;
    for (int i = 1; i <= N; ++i) {
        maxdeg = max(maxdeg, deg[i]);
    }

    cout << maxdeg + 1 << '\n';

    return 0;
}
