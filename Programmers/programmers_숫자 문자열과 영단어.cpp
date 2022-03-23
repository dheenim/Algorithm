#include <string>
#include <vector>
#include <iostream>
using namespace std;
string numbers[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int solution(string s) {
    int answer = 0;
    string ans = "";
    for(int idx=0;idx<s.length();idx++){
        if(s[idx]>='0'&&s[idx]<='9'){
            ans+=s[idx]; continue;
        }
        for(int i=0;i<10;i++){
            int len = numbers[i].length();
            
            if(numbers[i] == s.substr(idx,len)){
                ans += to_string(i);
                idx += len-1;
                break;
            }
        }
    }
    return answer=stoi(ans);
}
