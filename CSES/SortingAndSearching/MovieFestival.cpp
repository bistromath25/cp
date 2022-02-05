#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define dbg(x) {cout << "[" << (#x) << ": " << (x) << "]\n";}
#define dbgarr(a, n) {cout << "[" << (#a) << ": {"; int __n__ = 0; for (auto &__x__ : a) {cout << (__x__); ++__n__; if (__n__ >= n) {break;} else {cout << ", ";}}; cout << "}]\n";}
#define dbgarr2d(a, r, c) {cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {cout << (a[__i__][__j__]) << " ";} cout << "\n";}}
#define dbgmsg(msg) {cout << msg << "\n";}
vector<string> __split(string __s__) {__s__ += ", "; vector<string> __v__; while (!__s__.empty()) {__v__.push_back(__s__.substr(0, __s__.find(','))); __s__ = __s__.substr(__s__.find(',') + 2);} return __v__;}
void __dbg(vector<string>::iterator __it__) {cout << "\n";}
template<typename T, typename... Args>
void __dbg(vector<string>::iterator __it__, T t, Args... args) {cout << "[" << *__it__ << ": " << t << "] "; __dbg(++__it__, args...);}
#define debug(args...) {__dbg(__split(#args).begin(), args);}
#else
#define dbg(x)
#define dbgarr(a, n)
#define dbgarr2d(a, r, c)
#define dbgmsg(msg)
#define debug(args...)
#endif

void hello_world() {
    #if DEBUG
    freopen("INPUT.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #endif
}


int main() {
    hello_world();

    int n;
    cin >> n;
    vector<pair<int, int>> m;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        m.push_back({b, a});  // sort by end times
    }

    sort(m.begin(), m.end());
    int ans = 0;

    int curEnd = 0;
    for (int i = 0; i < n; ++i) {
        if (curEnd <= m[i].second) {
            ans++;
            curEnd = m[i].first;
        }
    }

    cout << ans << '\n';
    return 0;
}

