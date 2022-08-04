#include <iostream>
#include <exception>
using namespace std;

class MiddleSquareRNG {
private:
	unsigned long long state;
	unsigned long long div, mod;
public:
	MiddleSquareRNG() = delete;
	MiddleSquareRNG(unsigned long long seed) {		
		unsigned long long length = len(seed);
		if (length % 2 == 1) {
			throw invalid_argument("length of seed must be even");
		}
		div = 1;
		mod = 1;
		for (unsigned long long i = 0; i < length / 2; i++) {
			div *= 10;
		}
		for (unsigned long long i = 0; i < length; i++) {
			mod *= 10;
		}
		state = seed % mod;
	}
	unsigned long long next() {
		return state = state * state / div % mod;
	}
	unsigned long long len(unsigned long long x) {
		unsigned long long length = 0;
		while (x >= 10) {
			length++;
			x /= 10;
		}
		return length + 1;
	}
};

int main() {
	MiddleSquareRNG ms(123456);
	for (int i = 1; i <= 10; i++) {
		cout << ms.next() << endl;
	}
	return 0;
}
