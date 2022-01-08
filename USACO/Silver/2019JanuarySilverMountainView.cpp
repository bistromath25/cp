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


// mountain with peak (x, y) has left endpoint at x - y, and right endpoint at x + y on the x-axis
// mountain will be obscured by another if its left and right endpoints are contained within the other
// mountian's endpoint interval

const int MAXN = 1e5 + 1;
int N;
vector<pair<int, int>> mountains(MAXN);  // left endpoint of mountain, right endpoint of mountain

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;  // already pairs are compared this way
}

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);
    #endif

    cin >> N;
    mountains.resize(N);
    for (int i = 0, x, y; i < N; ++i) {
        cin >> x >> y;
        mountains[i] = {x - y, x + y};  // right and left endpoints
    }

    sort(mountains.begin(), mountains.end(), cmp);

    dbgarr(mountains, N);

    vector<bool> covered(N, false);  // has mountain i been covered by another?

    for (int i = 0; i < N; ++i) {
        if (covered[i]) continue;  // if this mountain's already been covered, skip it
        int il = mountains[i].first, ir = mountains[i].second;  // current left and right endpoints
        for (int j = i + 1; j < N; ++j) {  // for each next mountain
            int jl = mountains[j].first, jr = mountains[j].second;
            if (il <= jl && jr <= ir) {  // if covered
                covered[j] = true;
            }
            else if (ir < jl) break;  // if out of range
        }
    }

    dbgarr(covered, N);

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        ans += !covered[i];  // add to ans if not covered
    }

    cout << ans << '\n';

    return 0;
}
