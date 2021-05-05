#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    unordered_map<string, int> dic;
    for (char i = 'A'; i <= 'Z'; i++) {
        string tmp = "";
        tmp += i;
        dic[tmp] = (i-'A'+1);
    }
    int dicIdx = 27;
    for(int idx=0;idx<msg.length();idx++){
        //cout<<"idx:"<<idx<<endl;
        string str="";
        str+=msg[idx];
        int cnt = 1;
        auto it=dic.find(str);
        int num = it->second;
        while(1){
            str+=msg[idx+cnt]; cnt++;
            it = dic.find(str);
            if(it==dic.end()) break;
            else{
                num = it->second;
            }
        }
        //cout<<"str:"<<str<<" num:"<<num<<endl;
        dic[str] = dicIdx++;
        answer.push_back(num);

        idx = idx + cnt -2;
    }
    return answer;
}
