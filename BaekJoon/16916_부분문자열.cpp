#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> getPi(string p)
{
    int m = (int)p.size();
    int j = 0;

    vector<int> pi(m, 0);

    for (int i = 1; i < m; i++) {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    /*for (int c = 0; c < pi.size(); c++) {
        cout << pi[c] << endl;
    }*/
    return pi;
}

bool kmp(string s, string p)
{
    vector<int> ans;
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == m - 1) {
                return true;
            }
            else {
                j++;
            }
        }
    }
    return false;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str, sub;
	cin >> str;
	cin >> sub;
    cout << kmp(str, sub);
	//vector<int> idxs;
	//auto idx = str.find(sub);
	//while (idx != string::npos) {
	//	idxs.push_back(idx);
	//	idx = str.find(sub, idx + 1);
	//}
	//bool chk = false;
	//for (int i = 0; i < idxs.size(); i++) {
	//	if (str.compare(idxs[i], sub.length(), sub) == 0) {
	//		chk = true;
	//		break;
	//	}
	//	/*if (str.substr(idxs[i], sub.length()) == sub) {
	//		chk = true;
	//		break;
	//	}*/
	//}
	//cout << chk << endl;
	return 0;
}