#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n;
int arr[11];
int form[4];
long long mx = -1000000000;
long long mn = 1000000000;
void dfs(long long cnt,long long sum){
    if(cnt==n){
        mx = max(mx,sum);
        mn = min(mn,sum);
        return;
    }
    for(int i=0;i<4;i++){
        if(form[i]!=0){
            if(i==0){
                form[i]-=1;
                dfs(cnt+1,sum+arr[cnt]);
                form[i]+=1;
            }
            if(i==1){
                form[i]-=1;
                dfs(cnt+1,sum-arr[cnt]);
                form[i]+=1;
            }
            if(i==2){
                form[i]-=1;
                dfs(cnt+1,sum*arr[cnt]);
                form[i]+=1;
            }
            if(i==3){
                form[i]-=1;
                dfs(cnt+1,sum/arr[cnt]);
                form[i]+=1;
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<4;i++)
        cin>>form[i];
    dfs(1,arr[0]);
    cout << mx <<"\n"<<mn<<"\n";
}
