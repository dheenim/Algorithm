#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int input[101][101];
int rowNum, colNum;
int ans = 0;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}
int Rop();
int Cop();

int main() {
	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> input[i][j];
		}
	}
	rowNum = 3; colNum = 3;

	while (ans <= 100 && input[r][c] != k) {
		if (rowNum >= colNum) {
			colNum = Rop();
		}
		else {
			rowNum = Cop();
		}
		ans++;
		/*cout << "ans : " << ans <<"row:"<<rowNum<<"  col:"<<colNum<< "---------------------\n";
		for (int i = 1; i <= rowNum; i++) {
			for (int j = 1; j <= colNum; j++) {
				cout << input[i][j] << " ";
			}
			cout << "\n";
		}*/
	}
	if (ans < 101)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}

int Rop() {
	int max_colSize = 0;
	for (int row = 1; row <= rowNum; row++) {
		//cout << "\nrow:" << row << endl;
		int count[101] = { 0, };
		for (int col = 1; col <= colNum; col++) {
			//cout << "row:" << row << " col:" << col << " ->" << input[row][col] << endl;
			count[input[row][col]]++;
		}
		vector<pair<int, int>> v;
		for (int i = 1; i <= 100; i++) {
			if (count[i] == 0) continue;
			v.push_back({ count[i],i });
		}
		sort(v.begin(), v.end(), cmp);
		/*for (int i = 0; i < v.size(); i++) {
			cout << v[i].first << " , " << v[i].second << "\n";
		}
		cout << endl;*/
		int idx = 1;
		for (int i = 0; i < v.size(); i++) {
			if (idx > 100) break;
			input[row][idx] = v[i].second;
			idx++;
			input[row][idx] = v[i].first;
			idx++;
		}
		if (max_colSize < idx - 1) max_colSize = idx - 1;
		while (idx <= 100) {
			input[row][idx] = 0;
			idx++;
		}
	}
	return max_colSize;
}

int Cop() {
	int max_rowSize = 0;
	for (int col = 1; col <= colNum; col++) {
		int count[101] = { 0, };
		for (int row = 1; row <= rowNum; row++) {
			count[input[row][col]]++;
		}
		vector<pair<int, int>> v;
		for (int i = 1; i <= 100; i++) {
			if (count[i] == 0) continue;
			v.push_back({ count[i],i });
		}
		sort(v.begin(), v.end(), cmp);
		int idx = 1;;
		for (int i = 0; i < v.size(); i++) {
			if (idx > 100) break;
			input[idx][col] = v[i].second;
			idx++;
			input[idx][col] = v[i].first;
			idx++;
		}

		if (max_rowSize < idx - 1) max_rowSize = idx - 1;
		while (idx <= 100) {
			input[idx][col] = 0;
			idx++;
		}
	}
	return max_rowSize;
}