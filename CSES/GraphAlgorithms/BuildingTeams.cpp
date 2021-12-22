#define DEBUG 0
 
#include <bits/stdc++.h>
using namespace std;
 
#if DEBUG
#define dbg(x) {cout << "[" << (#x) << ": " << (x) << "]\n";}
#define dbgarr(a, n) {auto __it__ = begin(a); cout << "[" << (#a) << ": {" << *__it__; int __cnt__ = 1; while (__cnt__ < n) {cout << ", " << *(++__it__); ++__cnt__;} cout << "}]\n";}
#define dbgarr2d(a, r, c) {cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {cout << (a[__i__][__j__]) << " ";} cout << "\n";}}
#define dbgmsg(msg) {cout << msg << "\n";}
vector<string> __split(const string& __s__, char __c__) {vector<string> __res__; stringstream __ss__(__s__); string __x__; while (getline(__ss__, __x__, __c__)) {__res__.push_back(__x__);} return (__res__);}
void __dbg(vector<string>::iterator __it__) {}
template<typename T, typename... Args>
void __dbg(vector<string>::iterator __it__, T t, Args... args) {cout << "[" << __it__->substr((*__it__)[0] == ' ') << ": " << t << "] "; __dbg(++__it__, args...);}
#define debug(args...) {vector<string> __args__ = __split(#args, ','); __dbg(__args__.begin(), args); cout << "\n";}
#else
#define dbg(x)
#define dbgarr(a, n)
#define dbgarr2d(a, r, c)
#define dbgmsg(msg)
#define debug(args...)
#endif
 
 
const int N = 1e5 + 10, M = 2e5;
int n, m;
vector<int> friendships[N];
bool visited[N];
int color[N];
bool ok = true;
 
void dfs(int x, int c) {
    if (visited[x]) return;
    visited[x] = true;
    color[x] = c;
    for (const int &y : friendships[x]) {
        if (!visited[y]) {
            dfs(y, 1 - c);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    #if DEBUG
    dbgmsg("Reading INPUT.in");
    freopen("INPUT.in", "r", stdin);
    #endif
 
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        friendships[a].push_back(b);
        friendships[b].push_back(a);
    }
 
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
 
    for (int i = 0; i < n; ++i) {
        for (const int &j : friendships[i]) {
            if (color[i] == color[j]) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        cout << color[i] + 1 << ' ';
    }
    cout << '\n';
 
    return 0;
}
