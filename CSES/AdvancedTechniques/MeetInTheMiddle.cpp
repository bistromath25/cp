#include <bits/stdc++.h>
using namespace std;

// technique used if bruteforce too slow
// split elements into two sets, find all possible sums of each set
// iterate through the first and use binary search on the second set to determine the sums
// O(2^n) -> O(2^(n/2))

int n, x;

int main() {

	//freopen("input.in", "r", stdin);

	cin >> n >> x;
	int m1 = n / 2;
	int m2 = n - m1;

	vector<int> a1(m1), a2(m2);  // split original set into two parts
	for (int i = 0; i < m1; ++i) {
		cin >> a1[i];
	}
	for (int i = 0; i < m2; ++i) {
		cin >> a2[i];
	}

	vector<long long> sum1, sum2;  // store the sums
	for (int i = 0; i < (1 << m1); ++i) {  // bit masking stuff
		long long sum = 0;
		for (int j = 0; j < m1; ++j) {
			if (i & (1 << j)) {
				sum += a1[j];
			}
		}
		sum1.push_back(sum);
	}
	for (int i = 0; i < (1 << m2); ++i) {
		long long sum = 0;
		for (int j = 0; j < m2; ++j) {
			if (i & (1 << j)) {
				sum += a2[j];
			}
		}
		sum2.push_back(sum);
	}

	sort(sum1.begin(), sum1.end());  // binary search (must sort arrays first)
	sort(sum2.begin(), sum2.end());

	long long ans = 0;
	for (long long s1 : sum1) {  // check if this sum is possible (count how many ways to make a certain sum)
		ans += upper_bound(sum2.begin(), sum2.end(), x - s1) - lower_bound(sum2.begin(), sum2.end(), x - s1);
	}

	cout << ans << '\n';

	return 0;
}
