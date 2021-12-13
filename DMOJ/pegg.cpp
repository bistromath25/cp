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
#define dbg(x) {cout << "[" << (#x) << ": "; __dbg(x); cout << "]\n";}
#define dbgarr(a, n) {cout << "[" << (#a) << ": {"; int __n__ = 0; for (const auto &__x__ : a) {__dbg(__x__); ++__n__; if (__n__ >= n) {break;} else {cout << ", ";}} cout << "}]\n";}
#define dbgarr2d(a, r, c) {cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {cout << (a[__i__][__j__]) << " ";} cout << "\n";}}
#define dbgmsg(msg) {cout << msg << "\n";}
#define debug(args...) {__debug_out(__split(#args).begin(), args);}
#else
#define dbg(x)
#define dbgarr(a, n)
#define dbgarr2d(a, r, c)
#define dbgmsg(msg)
#define debug(args...)
#endif

// n eggs, k floors, x attempts
long long binomial(long long n, long long k, long long x) {
    // find C(n, k)
    long long a = 1;
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
        a *= (x - i + 1);
        a /= i;
        ans += a;
        if (ans > k) {
            break;
        }
    }
    return ans;
}

void solve() {
    long long floors;
    long long eggs;
    cin >> floors >> eggs;

    debug(floors, eggs);

    long long low = 1, high = floors;
    long long mid = 0;
    long long ans = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        debug(low, mid, high);
        long long b = binomial(eggs, floors, mid);
        if (b >= floors) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if (ans <= 32) {
        cout << ans << '\n';
    }
    else {
        cout << "Impossible\n";
    }
}

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        solve();
    }
    return 0;
}
