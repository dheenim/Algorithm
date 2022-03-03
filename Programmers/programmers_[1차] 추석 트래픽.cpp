#include <string>
#include <vector>
using namespace std;
pair<int,int> splitWord(string str){
    string hh="";
    hh += str[11]; hh+= str[12];
    string mm="";
    mm += str[14]; mm+= str[15];
    string ss="";
    ss += str[17]; ss+= str[18];
    string sss="";
    sss+= str[20]; sss+= str[21]; sss+= str[22];
    string t="";
    for(int i=24; i<str.length()-1; i++){
        t+= str[i];
    }
    int milisec = stoi(sss) + (stoi(ss) + stoi(mm)*60 + stoi(hh)*3600)*1000;
    int miliT = stod(t)*1000;
    return {milisec, miliT};
}

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> startTime, endTime;
    for(auto str:lines){
        pair<int,int> val = splitWord(str);
        endTime.push_back(val.first);
        startTime.push_back(val.first-val.second+1);
    }
    for(int i=0;i<endTime.size();i++){
        int cnt=0;

        for(int k=i;k<startTime.size();k++){
            if(startTime[k]<endTime[i]+1000)cnt++;
        }
        if(answer<cnt) answer = cnt;
    }
    return answer;
}
