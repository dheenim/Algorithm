#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < course.size(); i++) {
        int pick = course[i];
        cout << "picks:" << pick << endl;
        vector<int> ind;
        for (int k = 0; k < pick; k++) ind.push_back(1);
        for (int k = 0; k < 26 - pick; k++) ind.push_back(0);
        sort(ind.begin(), ind.end());
        vector<pair<int, string>> newStr;
        do {
            string alp = "";
            for (int idx = 0; idx < ind.size(); idx++) {
                if (ind[idx] == 1) {
                    alp += ('A' + idx);
                }
            }
            //cout << "alp: " << alp << endl;
            int cnt = 0;
            for (int a = 0; a < orders.size(); a++) {
                sort(orders[a].begin(), orders[a].end());
                if (includes(orders[a].begin(), orders[a].end(), alp.begin(), alp.end())) {
                    cnt++;
                }
            }
            if (cnt >= 2) {
                //cout << "alp:" << alp << " cnt:" << cnt << endl;
                newStr.push_back({ cnt,alp });
            }
        } while (next_permutation(ind.begin(), ind.end()));
        if (newStr.empty()) continue;

        sort(newStr.begin(), newStr.end(), cmp);
        int num = newStr[0].first;
        //cout << "num:"<<num<<endl;
        for (int k = 0; k < newStr.size(); k++) {
            if (num > newStr[k].first) break;
            answer.push_back(newStr[k].second);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
