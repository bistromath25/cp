#include <iostream>
#include <string>
using namespace std;

const long long M = 9973;
const long long P = 1000000007;

unsigned myhash(const string& s) {
    long long result = 0;
    for (int i = 0; i < s.size(); i++) {
        result = result * M + s[i];
        result %= P;
    }
    return result;
}

int rabin_karp(const string& needle, const string& haystack) {
    long long hash1 = myhash(needle);
    long long hash2 = 0;
    long long power = 1;

    for (int i = 0; i < needle.size(); i++) {
        power = (power * M) % P;
    }

    for (int i = 0; i < haystack.size(); i++) {
        hash2 = hash2 * M + haystack[i];
        hash2 %= P;

        if (i >= needle.size()) {
            hash2 -= power * haystack[i - needle.size()] % P;
            if (hash2 < 0) {
                hash2 += P;
            }
        }

        if (i >= needle.size() - 1 && hash1 == hash2) {
            return i - (needle.size() - 1);
        }
    }

    return -1;
}

int main() {
    cout << rabin_karp("string", "sstringss") << endl;
    cout << rabin_karp("string", "apple") << endl;
}
