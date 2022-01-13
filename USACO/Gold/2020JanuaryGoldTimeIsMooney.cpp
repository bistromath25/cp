#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
template<typename T>
void __dbg(const T &__x__) {cout << __x__;}
template<typename T1, typename T2>
void __dbg(const pair<T1, T2> &__x__) {cout << "(" << __x__.first << ", " << __x__.second << ")";}
vector<string> __split(string __s__) {__s__ += ", "; vector<string> __v__; while (!__s__.empty()) {__v__.push_back(__s__.substr(0, __s__.find(','))); __s__ = __s__.substr(__s__.find(',') + 2);} return __v__;}
void __debug_out(vector<string>::iterator __it__) {cout << "\n";}
template<typename T, typename... Args>
void __debug_out(vector<string>::iterator __it__, T t, Args... args) {cout << "[" << *__it__ << ": "; __dbg(t); cout << "] "; __debug_out(++__it__, args...);}
#define dbg(args...) {args;}
#define dbgarr(a, n) {cout << "[" << (#a) << ": {"; int __n__ = 0; for (const auto &__x__ : a) {__dbg(__x__); ++__n__; if (__n__ >= n) {break;} else {cout << ", ";}} cout << "}]\n";}
#define dbgarr2d(a, r, c) {cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {__dbg(a[__i__][__j__]); cout << " ";} cout << "\n";}}
#define dbgmsg(msg) {cout << msg << "\n";}
#define debug(args...) {__debug_out(__split(#args).begin(), args);}
#else
#define dbg(args...)
#define dbgarr(a, n)
#define dbgarr2d(a, r, c)
#define dbgmsg(msg)
#define debug(args...)
#endif

/*
Bessie travels for T days and makes at most 1000T - T^2, which means she makes 1000 money at each city and the cost C is 1
This is negative whenever T becomes greater than 1000, so the maximum number of days Bessie can travel is 1000.
*/

const int MAXDAYS = 1000;
const int MAXN = 1000;
int N, M, C;
vector<int> g[MAXN];
vector<int> moonies(MAXN);
int dp[MAXDAYS + 1][MAXN + 1];  // dp[i][j] = max money at day i ending at city j, 0-indexed

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    #endif

    cin >> N >> M >> C;
    moonies.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> moonies[i];
    }
    for (int i = 0, a, b; i < M; ++i) {
        cin >> a >> b;
        g[a - 1].push_back(b - 1);  // 0-indexed
    }

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;  // traveling for 0 days gets no moonies

    int ans = 0;
    for (int day = 0; day < MAXDAYS; ++day) {
        for (int city = 0; city < N; ++city) {
            if (dp[day][city] == -1) continue;
            else {
                for (int &nxt : g[city]) {
                    dp[day + 1][nxt] = max(dp[day + 1][nxt], dp[day][city] + moonies[city]);
                }
            }
        }
        ans = max(ans, dp[day][0] - C * day * day);
    }

    cout << ans << '\n';

    return 0;
}
