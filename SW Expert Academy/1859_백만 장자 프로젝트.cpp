#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<short> price;
//priority_queue<short> bigPrice;

int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) {
		long long ans = 0;
		int N;
		cin >> N;
		
		for (int j = 0; j < N; j++) {
			short num; cin >> num;
			price.push_back(num);
			//bigPrice.push(num);
		}

		long long curBuy = 0;
		int buyNum = 0;
		int maxPrice = *max_element(price.begin(), price.end());
		for (int idx = 0; idx < N; idx++) {
			if (maxPrice == price[idx]) {
				ans += price[idx] * buyNum - curBuy;
				curBuy = 0; buyNum = 0;
				if (idx == N - 1) continue;
				maxPrice = *max_element(price.begin() + idx + 1, price.end());
			}
			else {
				buyNum++;
				curBuy += price[idx];
			}
			/*if (bigPrice.top() == price[idx]) {
				ans += price[idx]*buyNum - curBuy;
				curBuy = 0; buyNum = 0;
				bigPrice.pop();
			}
			else {
				buyNum++;
				curBuy += price[idx];
			}*/
		}
		price.clear();
		//bigPrice = priority_queue<short>();

		cout << "#" << i << " " << ans << "\n";
	}
	return 0;
}
