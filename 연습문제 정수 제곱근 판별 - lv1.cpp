#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long tmp = 1;
    while(tmp*tmp<n) tmp++;
    if(tmp*tmp==n){
        return (tmp+1)*(tmp+1);
    }
    return -1;
}
