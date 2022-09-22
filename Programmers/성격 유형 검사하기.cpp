#include <string>
#include <vector>
#include <map>

using namespace std;
string character[4][2] = {{"R","T"},{"C","F"},{"J","M"},{"A","N"}};
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char,int> m;
    m['R']=0; m['T']=0;
    m['C']=0; m['F']=0;
    m['J']=0; m['M']=0;
    m['A']=0; m['N']=0;

    for(int i=0; i<survey.size();i++){
        if(choices[i]<4){
            m[survey[i][0]] += (4- choices[i]);
        }
        else if(choices[i] > 4){
            m[survey[i][1]] += (choices[i] - 4);
        }
    }
    
    for(int i=0;i<4;i++){
        if(m[character[i][0].c_str()[0]] >= m[character[i][1].c_str()[0]]){
            answer += character[i][0];
        }
        else
            answer += character[i][1];
    }
    return answer;
}
