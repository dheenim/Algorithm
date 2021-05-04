#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string str = "0";
    for(int num=1;num<=100000;num++){
        int tmp=num;
        string s="";
        int r,q;
        while(tmp>0){
            r=tmp%n;
            if(r>=10){
                s = (char)('A'+(r-10)) + s;
            }
            else s=to_string(r)+s;
            tmp = tmp/n;
        }
        str += s;
        if(str.length() > m*t+p) break;
    }
    int pos=p-1;
    string answer = "";
    while(answer.size()<t){
        answer+=str[pos];
        pos+=m;
    }
    return answer;
}
