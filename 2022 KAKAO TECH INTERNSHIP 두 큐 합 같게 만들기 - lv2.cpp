#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1=0;
    long long sum2=0;
    queue<int> q1;
    queue<int> q2;
    long maxcnt = queue1.size()*4;
    for(int i=0;i<queue1.size();i++){
        sum1+=queue1[i];
        sum2+=queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    if((sum1+sum2)%2==1)
        return -1;
    long long res = 0;
    while(sum1!=sum2 && !q1.empty()&&!q2.empty()){
        if(res>maxcnt)
            break;
        if(sum1>sum2){
            int tmp = q1.front();
            sum2+=tmp;
            sum1-=tmp;
            q2.push(tmp);
            q1.pop();
        }
        else if(sum1<sum2){
            int tmp = q2.front();
            sum2-=tmp;
            sum1+=tmp;
            q1.push(tmp);
            q2.pop();
        }
        res++;
    }
    if(sum1!=sum2)
        return -1;
    return res;
}
