#include <cmath>
using namespace std;

long long solution(int w,int h) {
    long long answer = (long long)w*h;
    double incli = (double)h/w;
    int before, after;
    for(int i=0;i<w;i++){
        before = floor(((double)h*i)/w);
        after = ceil(((double)h*(i+1))/w);
        answer = answer - (after - before);
    }
    return answer;
}
