#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto &a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define ff return 0
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 20, MAXX = 1e9;
int N, X;
int w[MAXN];
vector<pair<int, int>> dp(1 << MAXN, {MAXN + 1, MAXX + 1});

signed main() {
    //freopen("input.in", "r", stdin);

    cin >> N >> X;
    for (int i = 0; i < N; ++i) {
        cin >> w[i];
    }

    dp[0] = {1, 0};  // empty group takes 1 ride at 0 weight

    for (int msk = 1; msk < (1 << N); ++msk) {
        for (int i = 0; i < N; ++i) {
            if (msk & (1 << i)) {  // ith person used the elevator already
                pair<int, int> prevdp = dp[msk ^ (1 << i)];  // bit ops to get the "inverse" of the current mask (get number with bits swapped)
                int rides = prevdp.first, totalw = prevdp.second;  // which represents the complementary set (people not on this ride)
                if (totalw + w[i] <= X) {
                    totalw += w[i];
                }
                else {
                    totalw = w[i];
                    rides++;
                }
                dp[msk] = min(dp[msk], {rides, totalw});  // take the minimum
            }
        }
    }

    cout << dp[(1 << N) - 1].first << '\n';  // (1 << N) - 1 is the set of all people

    return 0;
}
