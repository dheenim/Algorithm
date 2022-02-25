#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    unordered_map<string,int> idxs;
    for(int i=0;i<id_list.size();i++){
        idxs[id_list[i]]=i;
    }
    unordered_map<string,set<string>> um;
    stringstream ss;
    for(int i=0;i<report.size();i++){
        ss.str(report[i]);
        string rper, rped;
        ss >> rper >> rped;
        um[rped].insert(rper);
        ss.clear();
    }
    for(auto it=um.begin(); it!= um.end(); it++){
        if(it->second.size()<k) continue;
        for(auto ed_it:it->second){
            int idx = idxs[ed_it];
            answer[idx]++;
        }
    }
    return answer;
}
