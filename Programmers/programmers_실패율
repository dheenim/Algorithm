#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<double,int> a, pair<double,int> b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int tot[200002]; int fail[200002];
    for(int i=0;i<stages.size();i++){
        fail[stages[i]]++;
        for(int num=1;num<=stages[i];num++)
            tot[num]++;
    }
    vector<pair<double, int>> v;
    for(int i=1;i<=N;i++){
        if(tot[i] == 0){
            v.push_back({0,i});
        }
        else v.push_back({(double)fail[i]/tot[i], i});
    }
    sort(v.begin(),v.end(), cmp);
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].second);
    }
    return answer;
}
