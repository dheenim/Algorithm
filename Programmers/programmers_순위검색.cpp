#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//cpp       java        python    0 1 2 (0 8 16)
//backend   frontend              0 1   (0 4)
//junior    senior                0 1   (0 2)
//chicken   pizza                 0 1   (0 1)
vector<int> infos[24];
int ans = 0;
void infoSplit(string str)
{
    //cout << "str:" << str << endl;
    vector<string> strv;
    string tmp = "";
    int pos = 0;
    int mul = 8;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            if (mul == 8) {
                if (tmp == "cpp") {
                    pos = pos + mul * 0;
                }
                else if (tmp == "java") {
                    pos = pos + mul * 1;
                }
                else {//python
                    pos = pos + mul * 2;
                }
                mul /= 2;
            }
            else if (mul == 4) {
                if (tmp == "backend") {
                    pos = pos + mul * 0;
                }
                else {//frontend
                    pos = pos + mul * 1;
                }
                mul /= 2;
            }
            else if (mul == 2) {
                if (tmp == "junior") {
                    pos = pos + mul * 0;
                }
                else {//senior
                    pos = pos + mul * 1;
                }
                mul /= 2;
            }
            else {//mul == 1
                if (tmp == "chicken") {
                    pos = pos + mul * 0;
                }
                else {//pizza
                    pos = pos + mul * 1;
                }
            }
            tmp = "";
        }
        else
        {
            tmp.push_back(str[i]);
        }
    }
    int val = stoi(tmp);
    infos[pos].push_back(val);
    //cout << "pos:" << pos << " val:" << val << endl;

    //return strv;
}
void dfs(vector<string> qry, int depth, int val, int pos) {
    if (depth == 4) {
        //cout << "pos:" << pos << " val:" << val << endl;
        auto iter = lower_bound(infos[pos].begin(), infos[pos].end(), val);
        if (iter == infos[pos].end()) {
            //ans = 0;
        }
        else {
            ans = ans + infos[pos].size() - (iter - infos[pos].begin());
        }
        //for (int i = 0; i < infos[pos].size(); i++) {
        //    //cout << "val:" << val << "infoposVal:" << infos[pos][i] << endl;
        //    if (infos[pos][i] >= val) ans++;
        //}
        return;
    }
    switch (depth) {
        case 0:
            if (qry[depth] == "cpp") {
                pos = pos;
            }
            else if (qry[depth] == "java") {
                pos = pos + 8 * 1;
            }
            else if(qry[depth] == "python"){//python
                pos = pos + 8 * 2;
            }
            else {// - 인 경우
                dfs(qry, depth + 1, val, pos);//cpp
                dfs(qry, depth + 1, val, pos + 8);//java
                pos = pos + 8 * 2;//python
            }
            dfs(qry, depth + 1, val, pos);
            break;
        case 1:
            if (qry[depth] == "backend") {
                pos = pos;
            }
            else if (qry[depth] == "frontend") {
                pos = pos + 4;
            }
            else {// - 인 경우
                dfs(qry, depth + 1, val, pos);//backend
                pos = pos + 4;//frontend
            }
            dfs(qry, depth + 1, val, pos);
            break;
        case 2:
            if (qry[depth] == "junior") {
                pos = pos;
            }
            else if (qry[depth] == "senior") {
                pos = pos + 2;
            }
            else {// - 인 경우
                dfs(qry, depth + 1, val, pos);//junior
                pos = pos + 2;//senior
            }
            dfs(qry, depth + 1, val, pos);
            break;
        default:
            if (qry[depth] == "chicken") {
                pos = pos;
            }
            else if (qry[depth] == "pizza") {
                pos = pos + 1;
            }
            else {// - 인 경우
                dfs(qry, depth + 1, val, pos);//chicken
                pos = pos + 1;//pizza
            }
            dfs(qry, depth + 1, val, pos);
            break;
    }
    return;
}

vector<string> querySplit(string str)
{
    vector<string> strv;
    string tmp = "";
    bool chk = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (i + 2 < str.length() && str[i] == 'a' && str[i + 1] == 'n' && str[i + 2] == 'd') {
            i += 3;
            continue;
        }
        if (str[i] == ' ')
        {
            strv.push_back(tmp);
            tmp = "";
        }
        else
        {
            tmp.push_back(str[i]);
        }
    }
    if (tmp.size() > 0)
        strv.push_back(tmp);
    //for (int i = 0; i < strv.size(); i++) cout << strv[i] << " ";
    //cout << endl;
    return strv;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    //vector<vector<string>> infos;
    vector<vector<string>> queries;
    
    for (int i = 0; i < info.size(); i++) {
        infoSplit(info[i]);
    }
    for (int i = 0; i < 24; i++) {
        sort(infos[i].begin(), infos[i].end());
    }
    //cout << "-----------------\n";
    for (int i = 0; i < query.size(); i++) {
        ans = 0;
        vector<string> qry = querySplit(query[i]);
        dfs(qry, 0, stoi(qry[4]), 0);
        //cout << "ans:" << ans << endl;
        answer.push_back(ans);
    }

    return answer;
}
int main() {
    solution({ "java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50" }, {"java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150"
});
}