#include <ctime>
#include <iostream>
using namespace std;

struct Timer {
	clock_t start;
	Timer() {
		start = clock();
	}
	~Timer() {
		cout << "execution time: " << fixed << setprecision(3) << (float) (clock() - start) / CLOCKS_PER_SEC << " s" << endl;
	}
};

template<typename F, typename... Args>
double timeit(F fun, Args&&... args) {
	clock_t start = clock();
	fun(forward<Args>(args)...);
	return ((double) (clock() - start) / CLOCKS_PER_SEC);
}

int myfun(int a, int b) {
	for (int i = 0; i <= 1e6; ++i) {}
	return a + b;
}

int main() {
	cout << timeit(myfun, 2, 2) << endl;
	return 0;
}
