#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF 10000000000
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> input;
	for (int i = 0; i < n; i++) {
		long long tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	int left, right, mid;
	vector<long long> answer;
	long long ans = INF;
	for (left = 0; left < n - 2; left++) {
		right = n - 1;
		mid = left + 1;
		while (1) {
			if (right <= mid) break;
			long long sum = input[left] + input[right] + input[mid];
			if (llabs(ans) > llabs(sum)) {
				ans = sum;
				answer.clear();
				answer.push_back(input[left]);
				answer.push_back(input[mid]);
				answer.push_back(input[right]);
			}
			if (sum < 0) mid++;
			else right--;
		}
	}

	//int left = 0, right = input.size() - 1;
	//long long ans = INF;
	////long long sum;
	//vector<int> answer;
	//while (left <= right - 2) {
	//	long long sum = input[left] + input[right];
	//	for (int i = left + 1; i < right; i++) {
	//		if (llabs(sum + input[i]) < llabs(ans)) {
	//			ans = sum + input[i];
	//			answer.clear();
	//			answer.push_back(input[left]);
	//			answer.push_back(input[right]);
	//			answer.push_back(input[i]);
	//		}
	//	}
	//	if (input[left] < 0 && input[right] < 0) {
	//		left++;
	//		continue;
	//	}
	//	else if (input[left] > 0 && input[right] > 0) {
	//		right--;
	//		continue;
	//	}
	//	if (llabs(input[left + 1] + input[right]) < llabs(input[left] + input[right - 1])) {
	//		left++;
	//	}
	//	else right--;
	//}
	sort(answer.begin(), answer.end());
	cout << answer[0] << " " << answer[1] << " " << answer[2] << "\n";
}