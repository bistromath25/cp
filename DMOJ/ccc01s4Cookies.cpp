#include <bits/stdc++.h>
using namespace std;

#define eprintf(args...) //fprintf(stdout, args)

int n;

struct Point {
    double x, y;
    void read() {
        cin >> x >> y;
    }
};

vector<Point> points(10);
double ans = 0.0;

double dist(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double diam(const Point a, const Point b, const Point c) {
    // r = abc/4*sqrt(s(s-a)(s-b)(s-c)
    // s is the semi perimeter: (a+b+c)/2
    double s1 = dist(a, b), s2 = dist(b, c), s3 = dist(a, c);
    double s = (s1 + s2 + s3) / 2;
    return ((s1 * s2 * s3) / 2) * sqrt(s * (s - s1) * (s - s2) * (s - s3));
}

int main() {
    //freopen("input.in", "r", stdin);
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        points[i].read();
    }

    double a, b, c, d, s;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                a = dist(points[i], points[j]);
                b = dist(points[j], points[k]);
                c = dist(points[i], points[k]);
                s = (a + b + c) / 2;
                d = 0;
                if ((s == 0) || (a * a + b * b - c * c < 0) || (b * b + c * c - a * a < 0) || (c * c + a * a - b * b < 0)) {
                    if (a > d) d = a;
                    if (b > d) d = b;
                    if (c > d) d = c;
                }
                else {
                    d = 2 * (a * b * c) / (4 * sqrt (s * (s - a) * (s - b) * (s - c)));
                }
                if (d > ans) {
                    ans = d;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
