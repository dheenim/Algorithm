#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void doOp(string op, vector<string> num);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string op; cin >> op;
		int nums; cin >> nums;
		string arr; cin >> arr;
		string num = "";
		vector<string> v;
		if(nums!=0)
		for (int j = 1; j < arr.length(); j++) {
			if (arr[j] == ',' || arr[j] == ']') {
				v.push_back(num);
				num.clear();
			}
			else {
				num += arr[j];
			}
		}
		
		doOp(op, v);
		//cout << "----------------\n";
	}
}
void doOp(string op, vector<string> num) {
	//cout << num.size() << endl;
	//cout << "op:" << op << endl;
	int idx = 0;
	bool order = true;
	int start = 0;
	int end = num.size() - 1;
	while (idx < op.length()) {
		//cout << "idx:" << idx << " -> " << op[idx] << endl;
		if (op[idx] == 'R') {
			order = !order;
		}
		else {
			if (start > end) {
				cout << "error\n";
				return;
			}
			if (order) {
				//num.erase(num.begin());
				start++;
			}
			else {
				end--;
			}
		}
		idx++;
	}
	if (start > end) {
		cout << "[]\n";
		return;
	}
	if (order) {
		cout << "[";
		for (int i = start; i <= end - 1; i++) {
			cout << num[i] << ",";
		}
		cout << num[end] << "]\n";
	}
	else {
		cout << "[";
		for (int i = end; i > start; i--) {
			cout << num[i] << ",";
		}
		cout << num[start] << "]\n";
	}
}