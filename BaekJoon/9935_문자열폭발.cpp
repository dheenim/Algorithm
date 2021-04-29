#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s, p;
    cin >> s >> p;
    string ans;
    for (int i = 0; i < s.length(); i++) {
        ans.push_back(s[i]);
        if (ans[ans.size() - 1] == p[p.size() - 1]) {
            //cout << "ans:" << ans << endl;
            bool chk = false;
            for (int j = 2; j <= p.size(); j++) {
                if (ans[ans.size() - j] != p[p.size() - j]) {
                    chk = true;
                    break;
                }
            }
            if (!chk) {
                ans.erase(ans.size() - p.size(), p.size());
            }
            //cout << "after ans:" << ans << endl;
        }
    }
    if (ans.size() == 0) {
        cout << "FRULA\n";
    }
    else cout << ans << "\n";
}