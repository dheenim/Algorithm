#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
set<int> v[9];
bool possible(int N, int number, int ans){
    //cout << N <<" "<<number<< " "<<ans<<endl;
    int concat = ans;
    while(concat>0){
        string str="";
        for(int i=0;i<concat;i++) str+=to_string(N);
        int newNum = stoi(str);
        if(concat==ans) {
            if(newNum==number) return true;
            v[ans].insert(newNum);
            concat--;
            continue;
        }
        int chkidx = ans - concat;
        for(auto i=v[chkidx].begin();i!=v[chkidx].end();i++){
            if((*i)==0){
                continue;
            }
            //cout <<"newNum:"<<newNum<<" *i:"<<*i<<endl;
            if(newNum*(*i) == number||newNum/(*i) == number || newNum-(*i) == number || (*i)+newNum == number || (*i)-newNum == number || (*i)/newNum == number) return true;
        v[ans].insert((*i)+newNum);
        v[ans].insert((*i)-newNum);
        v[ans].insert((*i)/newNum);
        v[ans].insert((*i)*newNum);
        v[ans].insert(newNum-(*i));
        v[ans].insert(newNum/(*i));
        }
        concat--;
    }
    return false;
}

int solution(int N, int number) {
    int answer = 0;
    if(N==number) return 1;
    v[1].insert(N);
    answer = 2;
    while(answer < 9){
        if(possible(N,number, answer)) break;
        answer++;
    }
    if(answer > 8) answer = -1;
    return answer;
}
