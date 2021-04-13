#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

void getPrime();
int N;

int main() {
	cin >> N;
	if (N == 1) {
		cout << 2 << endl;
		return 0;
	}
	getPrime();
}
void getPrime() {
	for (int num = N; num <= 100000000; num++) {
		bool primeTrue = true;
		for (int div = 2; div <= sqrt(num); div++) {
			if (num % div == 0) {
				primeTrue = false;
				break;
			}
		}
		if (primeTrue) {
			string str = to_string(num);
			string revStr = to_string(num);
			reverse(revStr.begin(), revStr.end());
			if (str == revStr) {
				cout << num << endl;
				return;
			}
		}
	}
}