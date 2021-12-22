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
 
const int N = 100, X = 1e6;
int n, x;
int coins[N] = {0};
int dp[X + 1] = {0};
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
 
    dbgarr(coins, n);
 
    dp[0] = 0;
    for (int i = 1; i <= x; ++i) {
 
        dp[i] = 1e9;
        for (int j = 0; j < n; ++j) {
 
            if (i - coins[j] >= 0) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
 
        }
 
    }
 
    dbgarr(dp, x);
 
    if (dp[x] == 1e9) {
        cout << "-1\n";
    }
    else cout << dp[x] << '\n';
 
    return 0;
}
