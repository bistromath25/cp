#include <bits/stdc++.h>
using namespace std;

/* Multiply two large numbers via FFT */

namespace FFT {

static constexpr long double PI = 3.141592653589793238462643383279502884;
static const char digits[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

static void fft(vector<complex<double>> &a, bool inv) {
    int n = (int) a.size();
    if (n == 1) {
        return;
    }

    vector<complex<double>> a0(n / 2), a1(n / 2);

    for (int i = 0; 2 * i < n; ++i) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, inv);
    fft(a1, inv);

    double angle = 2 * PI / n;
    if (inv) angle = -angle;

    complex<double> w(1), wn(cos(angle), sin(angle));

    for (int i = 0; 2 * i < n; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (inv) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

static vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    vector<complex<double>> fa(a.begin(), a.end());
    vector<complex<double>> fb(b.begin(), b.end());

    int n = 1;
    while (n < (int) (a.size() + b.size())) {
        n <<= 1;
    }

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; ++i) {
        fa[i] *= fb[i];
    }

    fft(fa, true);

    vector<int> result(n, 0);
    for (int i = 0; i < n; ++i) {
        result[i] = round(fa[i].real());
    }

    return result;
}

string multiply(string a, string b) {
    vector<int> va, vb, ab;  // store digits
    va.resize(a.length());
    vb.resize(b.length());

    for (int i = 0; i < (int) a.length(); ++i) {
        va.end()[-i - 1] = a[i] - '0';
    }
    for (int i = 0; i < (int) b.length(); ++i) {
        vb.end()[-i - 1] = b[i] - '0';
    }

    ab = multiply(va, vb);
    ab.push_back(0);

    int carry = 0;
    for (int &x : ab) {
        x += carry;
        carry = x / 10;
        x %= 10;
    }

    string result;
    bool start = false;
    for (vector<int>::reverse_iterator it = ab.rbegin(); it != ab.rend(); ++it) {
        start |= *it;
        if (start) {
            result += digits[*it];
        }
    }

    if (!start) {
        result += '0';
    }

    return result;
}

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;
    cout << FFT::multiply(a, b);


    return 0;
}

