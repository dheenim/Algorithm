#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#define INF 9223372036854775807
using namespace std;

int tc, N;
vector<pair<int, int>> point;
void getMin();

int main() {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		point.clear();
		cin >> N;
		for (int j = 0; j < N; j++) {
			int x, y;
			cin >> x >> y;
			point.push_back({ x,y });
		}
		getMin();
	}
}
void getMin() {
	vector<int> pick;
	for (int i = 0; i < N/2; i++) {
		pick.push_back(0);
	}
	for (int i = 0; i < N / 2; i++) {
		pick.push_back(1);
	}
	sort(pick.begin(), pick.end());
	double ans = INF;
	do {
		pair<double, double> sum = { 0,0 };
		for (int i = 0; i < N; i++) {
			if (pick[i] == 0) {
				sum.first += point[i].first;
				sum.second += point[i].second;
			}
			else {
				sum.first -= point[i].first;
				sum.second -= point[i].second;
			}
		}
		double calc = sum.first * sum.first + sum.second * sum.second;
		if (ans > calc) ans = calc;
	} while (next_permutation(pick.begin(), pick.end()));
	ans = sqrt(ans);
	printf("%.12lf\n", ans);
}