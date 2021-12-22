#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SmallMatrix {
    T a, b, c, d;

    SmallMatrix& init() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        return *this;
    }

    SmallMatrix& init(T _a, T _b, T _c, T _d) {
        a = _a;
        b = _b;
        c = _c;
        d = _d;
        return *this;
    }

    SmallMatrix& reset() {
        a = 1;
        b = 0;
        c = 0;
        d = 1;
        return *this;
    }

    SmallMatrix operator + (const T x) const {
        SmallMatrix result;
        result.a = a + x;
        result.b = b + x;
        result.c = c + x;
        result.d = d + x;
        return result;
    }

    SmallMatrix operator - (const T x) const {
        SmallMatrix result;
        result.a = a - x;
        result.b = b - x;
        result.c = c - x;
        result.d = d - x;
        return result;
    }

    SmallMatrix operator * (const T x) const {
        SmallMatrix result;
        result.a = a * x;
        result.b = b * x;
        result.c = c * x;
        result.d = d * x;
        return result;
    }

    SmallMatrix operator / (const T x) const {
        SmallMatrix result;
        result.a = a / x;
        result.b = b / x;
        result.c = c / x;
        result.d = d / x;
        return result;
    }

    SmallMatrix& operator += (const T x) {
        a += x;
        b += x;
        c += x;
        d += x;
        return *this;
    }

    SmallMatrix& operator -= (const T x) {
        a -= x;
        b -= x;
        c -= x;
        d -= x;
        return *this;
    }

    SmallMatrix& operator *= (const T x) {
        a *= x;
        b *= x;
        c *= x;
        d *= x;
        return *this;
    }

    SmallMatrix& operator /= (const T x) {
        a /= x;
        b /= x;
        c /= x;
        d /= x;
        return *this;
    }

    SmallMatrix operator * (const SmallMatrix& x) const {
        SmallMatrix result;
        result.a = a * x.a + b * x.c;
        result.b = a * x.b + b * x.d;
        result.c = c * x.a + d * x.c;
        result.d = c * x.b + d * x.d;
        return result;
    }

    static const SmallMatrix& identity() {
        static SmallMatrix id{T(1), T(0), T(0), T(1)};
        return id;
    }

    static SmallMatrix pow(const SmallMatrix& x, unsigned long long n) {
        if (n == 1) {
            return x;
        }
        else if (n == 0) {
            return identity();
        }
        else {
            SmallMatrix t = pow(x, n / 2);
            if (n & 1) {
                return x * t * t;
            }
            else {
                return t * t;
            }
        }
    }

    void print() {
        cout << a << ' ' << b << '\n' << c << ' ' << d << '\n';
    }
};

