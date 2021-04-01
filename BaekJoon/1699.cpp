#include <iostream>
#include <cmath>
#define MIN(a,b) ((a)<(b))?(a):(b)
using namespace std;

int arr[100001];

int main() {
	int N;
	cin >> N;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	for (int i = 4; i <= N; i++) {
		int rt = (int)sqrt(i);
		if ((int)pow(rt, 2) == i) {
			arr[i] = 1;
		}
		else {
			int min_ = 10000000;
			for (int k = rt; k > 0; k--) {
				if (min_ > 1 + arr[i - (int)pow((int)k, 2)]) {
					min_ = 1 + arr[i - (int)pow((int)k, 2)];
				}
			}
			arr[i] = min_;
		}
	}
	cout << arr[N]<<endl;
}