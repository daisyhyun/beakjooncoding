#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k;
int arr[101];
bool concen[101];
int value[100];
int main(){
    cin>>n>>k;
    memset(concen,false,sizeof(concen));
    for(int i=1;i<=k;i++){
        int tmp;
        cin>>tmp;
        arr[i]=tmp;
    }
    int res=0;
    int putin=0;
    for(int i=1;i<=k;i++){
        int now=arr[i];
        if(concen[now]){
            continue;
        }
        if(putin<n){
            concen[now]=true;
            putin++;
            continue;
        }
        int lastidx = -1;
        int lesstime = 100;
        int delnum;
        for(int j=1;j<=k;j++){
            if(concen[j]){   
                int tmptime = 0;
                int tmpidx=-1;
                for(int p=i+1;p<=k;p++){
                    if(arr[p]==j){
                        if(tmptime==0)
                            tmpidx = p;
                        tmptime++;
                    }
                }
                if(tmpidx==-1){
                    delnum = j;
                    break;
                }
                if(tmpidx>lastidx){
                    lastidx = tmpidx;
                    delnum = j;
                }
            }
        }
        concen[delnum]=false;
        concen[now]=true;
        res++;
    }
    cout << res;
}
