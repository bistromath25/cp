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


const long long INF = 1e18;
const int MAXN = 1e5 + 1, MOD = 1e9 + 7;
int N;
vector<pair<int, int>> segs;
vector<int> diff(MAXN), pref(MAXN);  // diff and pref sum arrays

vector<long long> p2(MAXN);

void fill_p2() {  // compute powers of 2
    p2[0] = 1;
    for (int i = 1; i <= N; ++i) {
        p2[i] = (2 * p2[i - 1]) % MOD;
    }
}

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("help.in", "r", stdin);
    freopen("help.out", "w", stdout);
    #endif

    cin >> N;
    segs.resize(N + 1);
    diff.resize(2 * N + 1);
    pref.resize(2 * N + 1);
    segs[0] = {0, 0};  // 1-index all the arrays
    diff[0] = 0;
    pref[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> segs[i].first >> segs[i].second;
        diff[segs[i].first]++;
        diff[segs[i].second]--;
    }

    pref[0] = 0;
    for (int i = 1; i <= 2 * N; ++i) {
        pref[i] = pref[i - 1] + diff[i];
    }

    for (int i = 1; i <= 2 * N; ++i) {
        pref[i] = max(0, pref[i] - 1);
    }

    fill_p2();

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += p2[N - 1 - pref[segs[i].first]];  // compute the contribution wrt the number of segments covering a certain point
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}

