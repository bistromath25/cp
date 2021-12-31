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


const int N = 1e5 + 1;
int n;
vector<int> p(N), t(N), d(N);

bool same_sign(int x, int y) {
    if (x > 0 && y > 0) {
        return true;
    }
    else if (x < 0 && y < 0) {
        return true;
    }
    else {
        return false;
    }
}

bool same_sign_2(int x, int y) {
    return x * y > 0;  // the product is positive
}

int solve() {
    int ans = 0, cur = 0, prev = 0;
    while (d[cur] == 0) cur++;

    int z = 0;

    while (z != n) {
        cur = prev;
        z = cur;

        while (d[cur] == 0) {  // move cur idx forward until d[cur] != 0
            cur++;
            z++;
        }

        if (cur >= n) break;

        for (int i = cur + 1; i < n && d[cur] * d[i] > 0; ++i) {
            if (d[cur] > 0) {
                d[i]--;
            }
            else {
                d[i]++;
            }
            if (d[i] == 0) z++;
        }

        if (d[cur] > 0) {
            d[cur]--;
        }
        else {
            d[cur]++;
        }

        if (d[cur] == 0) {
            z++;
        }

        ans++;

        dbgarr(d, n);
        debug(ans, z);

        prev = cur;
    }

    return ans;
}


void test() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> n;
        p.resize(n);
        t.resize(n);
        d.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> t[i];
        }

        for (int i = 0; i < n; ++i) {
            d[i] = p[i] - t[i];
        }

        cout << solve() << '\n';
    }
}

int main() {
    //freopen("input.in", "r", stdin);


    //#if DEBUG
    //test();
    //return 0;
    //#endif


    cin >> n;
    p.resize(n);
    t.resize(n);
    d.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i < n; ++i) {
        d[i] = p[i] - t[i];
    }

    cout << solve() << '\n';

    return 0;
}
