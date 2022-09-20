#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int st = 1;
    int cnt = 0;
    while(st<=n){
        int sum = 0;
        int tmp = st;
        while(1){
            sum +=tmp;
            tmp++;
            if(sum==n){
                cnt++;
                break;
            }
            if(sum>n){
                break;
            }
        }
        st++;
    }
    return cnt;
}
