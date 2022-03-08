#include <iostream>
#include<string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stk;
    //stk.push(s[0]);
    for(int i=0;i<s.length();i++){
        if(stk.empty()){
            stk.push(s[i]);
            continue;
        }
        if(stk.top()==s[i]){
            stk.pop();
        }
        else{
            stk.push(s[i]);
        }
    }
    if(stk.empty()) return 1;
    else return 0;
}
