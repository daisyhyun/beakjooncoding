#include <string>
#include <vector>
#include <queue>
using namespace std;

int itPrime(long n){
    if(n==1)
        return -1;
    long k = 2;
    while(k*k<=n){
        if(n%k==0)
            return -1;
        k++;
    }
    return 1;
}
int solution(int n, int k) {
    vector<int> pn;
    queue<int> q;
    while(n!=0){
        pn.push_back(n%k);
        n=n/k;
    }
    while(!pn.empty()){
        q.push(pn.back());
        pn.pop_back();
    }
    long tmp = 0;
    int lflag=0;
    int rflag=0;
    int qsize = q.size();
    int res=0;
    for(int i=0;i<qsize;i++){
        int nown = q.front();
        if(nown!=0){
            tmp = tmp*10+nown;
        }
        else{
            if(tmp!=0){
                int prime = itPrime(tmp);
                if(prime==1){
                    res++;
                }
                tmp=0;
            }
        }
        q.pop();
    }
    if(tmp!=0){
        int prime = itPrime(tmp);
        if(prime==1){
            res++;
        }
    }
    return res;
}
