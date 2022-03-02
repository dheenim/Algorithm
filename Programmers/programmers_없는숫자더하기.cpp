#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 45;
    vector<bool> chk(10,false);
    for(int i=0;i<numbers.size();i++){
        answer-=numbers[i];
    }
    return answer;
}
