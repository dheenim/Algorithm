#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize==0){
        return 5*cities.size();
    }
    int answer = 0;
    vector<string> v;
    for(int i=0;i<cities.size();i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto find_ = find(v.begin(),v.end(),cities[i]);
        if(find_==v.end()){
            if(v.size()<cacheSize) v.push_back(cities[i]);
            else{
                v.erase(v.begin());
                v.push_back(cities[i]);
            }
            answer+=5;
        }
        else{
            v.erase(find_);
            v.push_back(cities[i]);
            answer++;
        }
    }
    return answer;
}
