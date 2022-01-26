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

const int MAXN = 2500;
int N;
int value[MAXN];  // value of each vertex
vector<int> g[MAXN];  // bipartite graph
int cnt0 = 0, cnt1 = 0, sum0 = 0, sum1 = 0;  // count of each color 0 or 1, and the sum of the values of each vertex of that color

int dfs(int cur, int par, int col) {  // dfs on a tree
    if (col == 0) {
        cnt0;
        sum0 += value[cur];
    }
    else {
        cnt1++;
        sum1 += value[cur];
    }

    for (const int &nxt: g[cur]) {
        if (nxt != par) {
            dfs(nxt, cur, 1 - col);
        }
    }
}

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
    #endif

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> value[i];
    }
    for (int i = 1, a, b; i <= N - 1; ++i) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1, 0);

    if (sum0 % 12 == sum1 % 12) {  // if the sums are equal we can start anywhere
        cout << N << '\n';
    }
    else if ((sum0 + 1) % 12 == sum1 % 12) {  // if the difference is 1, start at any node of the greater color
        cout << cnt1 << '\n';
    }
    else if (sum0 % 12 == (sum1 + 1) % 12) {
        cout << cnt0 << '\n';
    }
    else {  // difference too great
        cout << "0\n";
    }

    return 0;
}
