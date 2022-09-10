#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int tmp=1;
    while(tmp*tmp<=n){
        if(n%tmp==0){
            if(tmp*tmp==n){
                answer+=tmp;
            }
            else{
                answer+=tmp;
                answer+=(n/tmp);
            }
        }
        tmp++;
    }
    return answer;
}
