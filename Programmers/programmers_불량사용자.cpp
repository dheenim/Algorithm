#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <iostream>
using namespace std;

int bannedNum = 0;
int ans = 0;
set<string> set_;
set<set<string>> picks;
vector<vector<string>> v_;

void dfs(int row) {
    cout << "row:" << row << " setsize:" << set_.size() << endl;
    if (row == v_.size() && set_.size() == v_.size()) {
        picks.insert(set_);
        //ans++;
        return;
    }
    for (int i = 0; i < v_[row].size(); i++) {
        auto chk = set_.insert(v_[row][i]);
        if (chk.second) {
            cout << v_[row][i] << endl;
            dfs(row + 1);
            set_.erase(set_.find(v_[row][i]));
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    bannedNum = banned_id.size();
    int answer = 0;
    vector<vector<string>> v(banned_id.size());
    for (int i = 0; i < banned_id.size(); i++) {
        string s = banned_id[i];
        //cout << "i:" << i << " s:" << s << endl;
        for (int j = 0; j < user_id.size(); j++) {
            if (s.length() != user_id[j].length()) continue;
            int idx = 0;
            for (char c : s) {
               // cout << c << endl;
                if (c != user_id[j][idx] && c != '*') break;
                idx++;
            }
            if (idx == s.length()) {
                //cout << "i:"<<i<<" user_id[j]:"<<user_id[j] << endl;
                v[i].push_back(user_id[j]);
            }
        }
    }
    v_ = v;
    for (int i = 0; i < v_.size(); i++) {
        cout << "\ni:" << i << endl;
        for (int j = 0; j < v_[i].size(); j++) {
            cout << v_[i][j] << " ";
        }
    }
    dfs(0);
    answer = picks.size();
    return answer;
}

int main() {
    vector<string> user_id; 
    vector<string> banned_id;
    //"frodo", "fradi", "crodo", "abc123", "frodoc"
    //"fr*d*", "*rodo", "******", "******"
    user_id.push_back("frodo");
    user_id.push_back("fradi");
    user_id.push_back("crodo");
    user_id.push_back("abc123");
    user_id.push_back("frodoc");
    banned_id.push_back("fr*d*");
    banned_id.push_back("*rodo");
    banned_id.push_back("******");
    banned_id.push_back("******");
    cout <<solution(user_id, banned_id);
}