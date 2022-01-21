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

int N, K, max_berries, ans = 0;
vector<int> berries(1000);
int M = INT_MAX;

bool cmp(const int &a, const int &b) {
    return (a % M) > (b % M);  // sort by remainder, descending (larger remainders before smaller ones)
}

int main() {
    #if DEBUG
    freopen("berries.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    #endif

    cin >> N >> K;
    berries.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> berries[i];
        max_berries = max(max_berries, berries[i]);
    }

    //sort(berries.begin(), berries.end());
    //reverse(berries.begin(), berries.end());
    //max_berries = berries[0];

    for (int i = 1; i <= max_berries; ++i) {  // each bucket might hold i berries
        int groups = 0;  // no. of buckets holding i berries each in total
        for (int j = 0; j <= N; ++j) {
            groups += berries[j] / i;
        }

        if (groups < K / 2) {  // not enough berries for K / 2 buckets
            continue;
        }
        else if (groups >= K) {  // enough berries, update ans if possible
            ans = max(ans, K / 2 * i);
        }
        else {  // more than K / 2 buckets, but less than K buckets
            M = i;  // each bucket will have M = i berries
            sort(berries.begin(), berries.end(), cmp);
            int ans2 = (groups - K / 2) * i;
            for (int j = 0; j < N && j + groups < K; ++j) {
                ans2 += berries[j] % i;  // number of berries we get from tree j
            }
            ans = max(ans, ans2);
        }
    }

    cout << ans << '\n';

    return 0;
}

