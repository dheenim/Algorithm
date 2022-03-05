#include <string>
#include <vector>
#include <iostream>
using namespace std;
char country124[3] = {'4','1','2'};
string solution(int n) {
    string answer = "";
    int r;
    while(n>0){
        r = n%3;
        //answer.insert(answer.begin(),country124[r]);
        answer = country124[r]+answer;
        n = n/3;
        if(r==0) n--;
    }
    return answer;
}
