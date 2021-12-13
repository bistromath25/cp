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


template<class T>
class DisjointSet {
private:
    unordered_map<T, int> parent, tree_size;
public:
    void init(vector<T> const& v) {
        for (T x : v) {
            make_set(x);
        }
    }
    void make_set(T x) {
        parent[x] = x;
        tree_size[x] = 0;
    }
    int find_set(T x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find_set(parent[x]);
    }
    void merge_sets(T x, T y) {
        x = find_set(x);
        y = find_set(y);
        if (x != y) {
            if (tree_size[x] > tree_size[y]) {
                parent[y] = x;
            }
            else if (tree_size[x] < tree_size[y]) {
                parent[x] = y;
            }
            else {
                parent[x] = y;
                tree_size[y]++;
            }
        }
    }
};

template<class T>
void print_sets(vector<T> const &v, DisjointSet<T> &ds) {
    for (int x : v) {
        cout << ds.find_set(x) << ' ';
    }
    cout << '\n';
}


const int N = 1e5 + 1;
int n, m;
pair<int, int> f[N];
vector<pair<pair<int, int>, int>> edges;
DisjointSet<int> DS;

bool cmp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
    return a.second < b.second;
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
    for (int i = 1; i <= n; ++i) {
        cin >> f[i].first;
        f[i].second = i;
    }

    sort(f + 1, f + 1 + n);

    vector<int> tmp(n, 0);
    for (int i = 1; i < n; ++i) {
        edges.push_back({{f[i].second, f[i + 1].second}, f[i + 1].first - f[i].first});
        tmp[i] = i;
    }

    DS.init(tmp);

    sort(edges.begin(), edges.end(), cmp);  // smallest friend weights first

    for (int i = 1, x, y; i <= m; ++i) {
        cin >> x >> y;
        DS.merge_sets(x, y);
    }

    long long ans = 0;

    for (const pair<pair<int, int>, int> &edge : edges) {
        int x = edge.first.first, y = edge.first.second, w = edge.second;
        if (DS.find_set(x) != DS.find_set(y)) {
            DS.merge_sets(x, y);
            ans += w;  // add cost of making x and y friends
        }
    }

    cout << ans << '\n';

    return 0;
}
