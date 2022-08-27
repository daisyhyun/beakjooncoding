#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define MAX 21

int n;
int arr[MAX][MAX];
int team[20];
int res;

void findscore(){
    vector<int> st;
    vector<int> lin;
    for(int i=1;i<=n;i++){
        if(team[i]==1)
            st.push_back(i);
        else
            lin.push_back(i);
    }
    int sum1 = 0;
    int sum2 = 0;
    for(int i :st){
        for(int j:st){
            if(i!=j){
                sum1+=arr[i][j];
            }
        }
    }
    for(int i :lin){
        for(int j:lin){
            if(i!=j){
                sum2+=arr[i][j];
            }
        }
    }
    res = min(res,abs(sum1-sum2));
}

void picked(int start,int cnt){
    if(cnt==(n/2)){
        findscore();
        return;
    }
    for(int i=start;i<=n;i++){
        if(team[i]==0){
            team[i] = 1;
            picked(i+1,cnt+1);
            team[i] = 0;
        }
    }
}

int main(){
    cin>>n;
    res = 99999;
    memset(team,0,sizeof(team));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin>>arr[i][j];
    }
    picked(1,0);
    cout << res;
}
