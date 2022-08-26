#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n,m;
long long b;
int arr[501][501];

int main(){
    cin>>n>>m>>b;
    long long res = 2000000000;
    long long resla;
    int laymin = 0;
    int laymax = 256;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            laymin  = min(laymin,arr[i][j]);
            laymax = max(laymax,arr[i][j]);
        }
    }
    int st = laymin;
    int ed = laymax;
    for(int k=laymin;k<=laymax;k++){
        long long time = 0;
        long long tmpb = b;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(k==arr[i][j])
                    continue;
                else if(k>arr[i][j]){
                    time+= k-arr[i][j];
                    tmpb-=k-arr[i][j];
                }
                else{
                    tmpb+=arr[i][j]-k;
                    time+=(arr[i][j]-k)*2;
                }
            }
        }   
        if(tmpb>=0){
            if(res>time){
                res = time;
                resla = k;
            }
            else if(res==time)
                resla = k;
        }
    }
    cout << res<< " " << resla;
}
