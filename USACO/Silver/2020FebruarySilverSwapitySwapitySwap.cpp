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

const int MAXN = 1e5, MAXM = 100, MAXK = 1e9;
int N, M, K;
int finalpos[MAXN + 1];  // position of each cow after one swap process
bool vis[MAXN + 1];
int ans[MAXN + 1];

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    #endif

    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        finalpos[i] = i;
    }

    // simulate swapping
    for (int i = 1, l, r; i <= M; ++i) {
        cin >> l >> r;
        reverse(finalpos + l, finalpos + 1 + r);
    }

    // process this cow only if not already processed/visited
    for (int i = 1; i <= N; ++i) {
        int cur = i;
        if (vis[cur]) continue;
        vis[cur] = true;
        vector<int> cycle;  // current cycle
        int nxt = finalpos[i];
        cycle.push_back(cur);
        while (nxt != cur) {  // while not at the original position
            vis[nxt] = true;
            cycle.push_back(nxt);
            nxt = finalpos[nxt];  // move nxt forward
        }

        int offset = K % cycle.size();  // index in the cycle after K swapping processes
        for (int j = 0; j < cycle.size(); ++j) {
            // for each j in the cycle, the actual final position of j will be
            // j + offset, since it must move forward offset steps
            ans[cycle[j]] = cycle[(j + offset) % cycle.size()];
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
