#include <iostream>
using namespace std;

long long arr[1000001];

int T,n;

int main() {
	cin >> T;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	int max = 3;
	for (int i = 0; i < T; i++) {
		int num;
		cin >> num;
		if (max >= num) {
			cout << arr[num]% 1000000009 << endl;
			continue;
		}
		for (int j = max + 1; j <= num; j++) {
			arr[j] = (arr[j - 1] + arr[j - 2] + arr[j - 3]) % 1000000009;
		}
		max = num;
		cout << arr[num] % 1000000009 << endl;
	}

}