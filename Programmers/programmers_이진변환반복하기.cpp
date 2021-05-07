#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zeros=0;
    int count = 0;
    while(1){
        int len = s.length();
        if(len==1&&s=="1") break;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                zeros++;
                len--;
            }
        }
        s.clear();
        int q,r;
        do{
            r = len%2;
            len = len/2;
            s = to_string(r) + s;
        }while(len>0);
        count++;
    }
    answer.push_back(count);
    answer.push_back(zeros);
    return answer;
}
