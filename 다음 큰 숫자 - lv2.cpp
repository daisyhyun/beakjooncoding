#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int firone = 0;
    int tmpn = n;
    while(tmpn!=0){
        if(tmpn%2==1)
            firone++;
        tmpn/=2;
    }
    for(int i=n+1;;i++){
        int secone = 0;
        tmpn = i;
        while(tmpn!=0){
            if(tmpn%2==1)
                secone++;
            tmpn/=2;
        }
        if(firone==secone)
            return i;
    }
   // return answer;
}
