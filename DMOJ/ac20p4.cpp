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


const int N = 3005, INF = 1e9;
int n, m;
int a[N], b[N];
vector<int> g[N];
bool edge[N][N];

bool cmp(vector<int> a, vector<int> b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    else {
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] > b[i]) {
                return false;
            }
            else if (a[i] < b[i]) {
                return true;
            }
        }
    }
    return false;
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

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
        edge[a[i]][b[i]] = true;
        edge[b[i]][a[i]] = true;
    }

    vector<int> ans(5, INF);
    for (int i = 1; i <= n; ++i) {
        for (const int &x : g[i]) {
            for (const int &y : g[i]) {
                if (x != y && edge[x][y]) {
                    vector<int> temp = {i, x, y};
                    sort(temp.begin(), temp.end());
                    ans = min(ans, temp, cmp);
                }
            }
        }
    }

    for (int i = 0; i < m - 1; ++i) {
        for (int j = i + 1; j < m; ++j) {
            vector<int> temp = {a[i], b[i], a[j], b[j]};
            sort(temp.begin(), temp.end());
            temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
            if (temp.size() > 3) {
                ans = min(ans, temp, cmp);
            }
        }
    }

    if (ans.size() > 4) {
        cout << "-1\n";
    }
    else {
        cout << ans.size() << '\n';
        for (const int &x : ans) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
