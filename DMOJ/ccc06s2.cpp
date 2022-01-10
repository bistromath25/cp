#define DEBUG 1

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

int main() {
    #if DEBUG
    freopen("input.in", "r", stdin);
    #else
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    #endif

    string plaintext, ciphertext1, ciphertext2;
    getline(cin, plaintext);
    getline(cin, ciphertext1);
    getline(cin, ciphertext2);

    debug(plaintext);
    debug(ciphertext1);
    debug(ciphertext2);

    map<char, char> key, key2;
    set<char> nope;

    int p = plaintext.length(), c1 = ciphertext1.length(), c2 = ciphertext2.length();

    for (char x = 'A'; x <= 'Z'; ++x) {
        key[x] = '.';
    }

    for (int i = 0; i < p; ++i) {
        char pp = plaintext[i], cc = ciphertext1[i];
        if (key[pp] != cc && key[pp] != '.') {
            key2[cc] = '.';
        }
        else {
            debug(pp, cc);
            key[pp] = cc;
            key2[cc] = pp;
        }
    }

    string result = "";


    cout << result << '\n';

    return 0;
}
