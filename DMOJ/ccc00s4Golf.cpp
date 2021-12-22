#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

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

const int INF = 1e9;
int dist, n;
vector<int> clubs;
int dp[5281] = {INF};

int main() {
    cin >> dist >> n;
    clubs.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> clubs[i];
    }

    sort(all(clubs));

    dp[0] = 0;
    for (int d = 1; d <= dist; ++d) {
        int m = INF;
        for (int i = 0; i < n; ++i) {
            int x = d - clubs[i];
            if (x >= 0 && dp[x] >= 0 && dp[x] < m) {
                m = dp[x];
            }
        }
        if (m < INF) {
            dp[d] = m + 1;
        }
        else {
            dp[d] = -1;
        }
    }

    dbgarr(dp, dist);

    if (dp[dist] != -1) {
        cout << "Roberta wins in " << dp[dist] << " strokes.\n";
    }
    else {
        cout << "Roberta acknowledges defeat.\n";
    }

    return 0;
}
