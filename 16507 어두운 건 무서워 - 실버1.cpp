#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;
int r,c,t;
int arr[1001][1001];
int sum[1001][1001];
int r1,c1,r2,c2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>r>>c>>t;
    memset(arr,0,sizeof(arr));
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
        }
    }
    
    for(int tc=1;tc<=t;tc++){
        cin>>r1>>c1>>r2>>c2;
        cout<<(sum[r2][c2]-sum[r1-1][c2]-sum[r2][c1-1]+sum[r1-1][c1-1])/((r2-r1+1)*(c2-c1+1))<<"\n";
    }
}   
