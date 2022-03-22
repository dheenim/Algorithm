#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#define MAXNUM 10000000
using namespace std;

bool primeNum[MAXNUM];
void getPrimeNum(){
    memset(primeNum,true, sizeof(primeNum));
    primeNum[0] = false; primeNum[1] = false;
    int prime = 2;
    while(prime<MAXNUM){
        if(!primeNum[prime]){
            prime++;
            continue;
        }
        for(int i=2;i*prime<MAXNUM;i++){
            primeNum[i*prime] = false;
        }
        prime++;
    }
}

int solution(string numbers) {
    int answer = 0;
    set<int> s;
    getPrimeNum();
    sort(numbers.begin(),numbers.end());
    do{
        for(int cnt=1;cnt<=numbers.length();cnt++){
            for(int idx=0;idx+cnt<=numbers.length();idx++){
                int num = stoi(numbers.substr(idx,cnt));
                if(primeNum[num]){
                    s.insert(num);
                }
        }
    }
    }while(next_permutation(numbers.begin(),numbers.end()));
    
    answer = s.size();
    return answer;
}
