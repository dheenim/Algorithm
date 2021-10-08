#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>

#define MAX 9999999
using namespace std;
bool primes[MAX];
bool selected[8];
string num;
set<int> answers;

void getPrime(){
    primes[0] = true;
    primes[1] = true;
    for(int i=3;i<=MAX;i++){
        for(int div=2;div<=sqrt(i);div++){
            if(i%div==0) {
                primes[i] = true;
                break;
            }
        }
    }
}

void dfs(int sums, int cnt, string &v){
    if(sums == cnt){
        //cout << stoi(v)<<endl;
        if(!primes[stoi(v)]) answers.insert(stoi(v));
        return;
    }
    for(int i=0; i<num.size(); i++){
        if(selected[i]) continue;
        selected[i] = true;
        v.push_back(num[i]);
        dfs(sums+1, cnt, v);
        v.pop_back();
        selected[i] = false;
    }
}

int solution(string numbers) {
    num.clear();
    num = numbers;
    getPrime();
    answers.clear();
    int answer = 0;
    for(int i=1; i<=numbers.size(); i++){
        memset(selected,0,sizeof(selected));
        string v = "";
        dfs(0, i, v);
        v.clear();
    }
    //cout<<"answers:\n";
    //for(auto it=answers.begin();it!=answers.end();it++){
    //    cout<< *it <<" ";
    //}
    return answers.size();
}
