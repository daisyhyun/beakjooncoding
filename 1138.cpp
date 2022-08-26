#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int arr[11];

int main(){
    cin>>n;
    int res[11]={0,};
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        for(int j=1;j<=n;j++){
            if(tmp==0&&res[j]==0){
                res[j] = i;
                break;
            }
            else if(res[j]==0)
                tmp--;
        }
    }
    for(int i=1;i<=n;i++)
        cout << res[i] << " ";

}
