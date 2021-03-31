#include <iostream>
#define MIN(a,b) (((a)<(b))?(a):(b))
using namespace std;

int arr[1000001];

int main() {
	int N;
	cin >> N;
	arr[1] = 0;
	arr[2] = arr[3] = 1;
	for (int i = 4; i <= N; i++) {
		if (i % 2 == 0 && i % 3 == 0) {
			arr[i] = MIN(MIN(arr[i - 1], arr[i / 2]), arr[i / 3]) + 1;
		}
		else if (i % 2 == 0 && i % 3 != 0) {
			arr[i] = MIN(arr[i - 1], arr[i / 2]) + 1;
		}
		else if (i % 2 != 0 && i % 3 == 0) {
			arr[i] = MIN(arr[i - 1], arr[i / 3]) + 1;
		}
		else {
			arr[i] = arr[i - 1] + 1;
		}
	}
	cout << arr[N] << endl;
}