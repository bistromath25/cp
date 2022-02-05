#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
#define dbg(x) {cout << "[" << (#x) << ": " << (x) << "]\n";}
#define dbgarr(a, n) {auto __it__ = begin(a); cout << "[" << (#a) << ": {" << *__it__; int __cnt__ = 1; while (__cnt__ < n) {cout << ", " << *(++__it__); ++__cnt__;} cout << "}]\n";}
#define dbgarr2d(a, r, c) {cout << (#a) << ":\n"; for (int __i__ = 0; __i__ < (r); ++__i__) {for (int __j__ = 0; __j__ < (c); ++__j__) {cout << (a[__i__][__j__]) << " ";} cout << "\n";}}
#define dbgprf(args...) {fprintf(stdout, args); fprintf(stdout, "\n");}
vector<string> __split(const string& __s__, char __c__) {vector<string> __res__; stringstream __ss__(__s__); string __x__; while (getline(__ss__, __x__, __c__)) {__res__.push_back(__x__);} return (__res__);}
void __dbg(vector<string>::iterator __it__) {}
template<typename T, typename... Args>
void __dbg(vector<string>::iterator __it__, T t, Args... args) {cout << "[" << __it__->substr((*__it__)[0] == ' ') << ": " << t << "] "; __dbg(++__it__, args...);}
#define debug(args...) {vector<string> __args__ = __split(#args, ','); __dbg(__args__.begin(), args); cout << "\n";}
#else
#define dbg(x)
#define dbgarr(a, n)
#define dbgarr2d(a, r, c)
#define dbgprf(args...)
#define debug(args...)
#endif

void hello_world() {
    #if DEBUG
    cout << "Hello, World!\n";
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
    vector<long long> lengths(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
    }

    sort(lengths.begin(), lengths.end());

    long long ans = 0, med = lengths[n / 2];
    for (const int &length : lengths) {
        ans += abs(med - length);
    }

    cout << ans << '\n';

    return 0;
}
