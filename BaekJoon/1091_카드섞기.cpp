#include<vector>
#include<iostream>

using namespace std;

int N;
vector<int> origin;
vector<int> shuffle;

bool chkOrder(vector<int> chk);
vector<int> shuf(vector<int> c);
bool chkSame(vector<int> chk);

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		origin.push_back(tmp);
	}
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		shuffle.push_back(tmp);
	}
	if (chkOrder(origin)) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 1;
	vector<int> copy = shuf(origin);
	while (!chkOrder(copy)) {
		if (chkSame(copy)) {
			cout << -1 << endl;
			return 0;
		}
		vector<int> tmp = shuf(copy);
		copy.clear();
		copy = tmp;
		tmp.clear();
		ans++;
	}
	cout << ans << endl;
}
bool chkSame(vector<int> chk) {
	for (int i = 0; i < N; i++) {
		if (chk[i] != origin[i]) return false;
	}
	return true;
}
vector<int> shuf(vector<int> shuff) {
	vector<int> tmp(N);
	for (int i = 0; i < shuffle.size(); i++) {
		tmp[shuffle[i]] = shuff[i];
	}
	return tmp;
}
bool chkOrder(vector<int> chk) {
	for (int i = 0; i < chk.size(); i++) {
		if (chk[i] % 3 != i % 3) {
			return false;
		}
	}
	return true;
}