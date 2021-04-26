#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> userID;
    for (int i = 0; i < record.size(); i++) {
        //cout << "i:"<<i <<endl;
        bool change = false;
        if (record[i][0] != 'L') {
            if (record[i][0] == 'C') change = true;
            int idx = 0;
            while (record[i][idx] != ' ') idx++;
            idx++;
            string uid = "";
            while (record[i][idx] != ' ') {
                uid += record[i][idx];
                idx++;
            }
            idx++;
            //cout << "uid:"<<uid<<endl;
            string nick = "";
            while (idx < record[i].length()) {
                nick += record[i][idx];
                idx++;
            }
            //cout<<"nick:"<<nick<<endl;
            auto ret = userID.insert({ uid,nick });
            //if(!ret.second && change){
            if (!ret.second) {
                ret.first->second = nick;
            }
            //cout << userID[uid]<<endl;
        }
    }
    for (int i = 0; i < record.size(); i++) {
        //cout<<"i:"<<i<<endl;
        string res = "";
        int command;//0:enter, 1: leave
        if (record[i][0] == 'C') continue;
        if (record[i][0] == 'E') command = 0;
        else command = 1;
        int idx = 0;
        while (record[i][idx] != ' ') idx++;
        idx++;
        string uid = "";
        if (command == 0)
            while (record[i][idx] != ' ') {
                uid += record[i][idx];
                idx++;
            }
        else {
            while (record[i][idx] != '\0') {
                uid += record[i][idx];
                idx++;
            }
        }
        //cout << "uid:"<<uid<<endl;
        /*idx++;
        string nick = "";
        while(idx < record[i].length()){
            nick+=record[i][idx];
            idx++;
        }
        cout << "nick:"<<nick<<endl;*/
        res += userID[uid];
        if (!command) res += "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
        else res += "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
        answer.push_back(res);
    }

    return answer;
}
