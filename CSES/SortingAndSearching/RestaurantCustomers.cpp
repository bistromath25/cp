#define DEBUG 1

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

#if DEBUG
#define dbg(x) cout << "[" << (#x) << ": " << (x) << "]\n"
#define dbgarr(a, l) cout << "[" << (#a) << ": {"; for (int __i__ = 0; __i__ < (l - 1); ++__i__) {cout << (a[__i__]) << ", ";} cout << (a[l - 1]) << "}]\n"
#define dbgarr2d(a, r, c) cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {cout << (a[__i__][__j__]) << " ";} cout << "\n";}
#define dbgmsg(msg) cout << msg << "\n";
vector<string> __split(const string& __s__, char __c__) {vector<string> __res__; stringstream __ss__(__s__); string __x__; while (getline(__ss__, __x__, __c__)) {__res__.push_back(__x__);} return (__res__);}
void __dbg(vector<string>::iterator __it__) {}
template<typename T, typename... Args>
void __dbg(vector<string>::iterator __it__, T t, Args... args) {cout << "[" << __it__->substr((*__it__)[0] == ' ') << ": " << t << "] "; __dbg(++__it__, args...);}
#define debug(args...) {vector<string> __args__ = __split(#args, ','); __dbg(__args__.begin(), args); cout << "\n";}
#else
#define dbg(x)
#define dbgarr(a, l)
#define dbgarr2d(a, r, c)
#define dbgmsg(msg)
#define debug(args...)
#endif


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> customers;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        customers.push_back({a, 1});
        customers.push_back({b, -1});
    }

    sort(all(customers));

    for (pair<int, int> p : customers) {
        debug(p.first, p.second);
    }

    int ans = 0, cur = 0;

    for (pair<int, int> p : customers) {
        cur += p.second;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
    return 0;
}

