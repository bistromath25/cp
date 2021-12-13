#include <iostream>
using namespace std;

int main() {
    for (int i = 1, N, K; i <= 5; ++i) {
        cin >> N >> K;
        if ((K >> (N - 1)) & 1) cout << "ON\n";
        else cout << "OFF\n";
    }

    return 0;
}
