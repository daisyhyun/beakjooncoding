#include<iostream>

using namespace std;


int n;
int maparr[21][21];
typedef int(*arrP)[21];
arrP pushu(int arr[][21]){
    int hap[21][21]={0,};
    for(int j=0;j<n;j++){
        for(int i=1;i<n;i++){
            if(arr[i][j]==0){
                continue;
            }
            int ti = i;
            while(ti>0){
                if(arr[ti-1][j]==arr[ti][j]&&hap[ti-1][j]==0){
                    arr[ti-1][j] +=arr[ti][j];
                    arr[ti][j] = 0;
                    hap[ti-1][j] = 1;
                    break;
                }
                if(arr[ti-1][j]==0){
                    arr[ti-1][j] = arr[ti][j];
                    arr[ti][j] = 0;
                }
                else{
                    break;
                }
                ti--;
            }
        }
    }
    return arr;
}

arrP pushd(int arr[][21]){
    int hap[21][21]={0,};
    for(int j=0;j<n;j++){
        for(int i=n-2;i>=0;i--){
            if(arr[i][j]==0){
                continue;
            }
            int ti = i;
            while(ti<n-1){
                if(arr[ti+1][j]==arr[ti][j]&&hap[ti+1][j]==0){
                    arr[ti+1][j] +=arr[ti][j];
                    arr[ti][j] = 0;
                    hap[ti+1][j] = 1;
                    break;
                }
                if(arr[ti+1][j]==0){
                    arr[ti+1][j] = arr[ti][j];
                    arr[ti][j] = 0;
                }
                else{
                    break;
                }
                ti++;
            }
        }
    }
    return arr;
}


arrP pushr(int arr[][21]){
    int hap[21][21]={0,};
    for(int i=0;i<n;i++){
        for(int j=n-2;j>=0;j--){
            if(arr[i][j]==0){
                continue;
            }
            int tj = j;
            while(tj<n-1){
                if(arr[i][tj+1]==arr[i][tj]&&hap[i][tj+1]==0){
                    arr[i][tj+1] +=arr[i][tj];
                    arr[i][tj] = 0;
                    hap[i][tj+1] = 1;
                    break;
                }
                if(arr[i][tj+1]==0){
                    arr[i][tj+1] = arr[i][tj];
                    arr[i][tj] = 0;
                }
                else{
                    break;
                }
                tj++;
            }
        }
    }
    return arr;
}

arrP pushl(int arr[][21]){
    int hap[21][21]={0,};
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(arr[i][j]==0){
                continue;
            }
            int tj = j;
            while(tj>0){
                if(arr[i][tj-1]==arr[i][tj]&&hap[i][tj-1]==0){
                    arr[i][tj-1] +=arr[i][tj];
                    arr[i][tj] = 0;
                    hap[i][tj-1] = 1;
                    break;
                }
                if(arr[i][tj-1]==0){
                    arr[i][tj-1] = arr[i][tj];
                    arr[i][tj] = 0;
                }
                else{
                    break;
                }
                tj--;
            }
        }
    }
    return arr;
}
int res = 0;
void dfs(int cnt, int bloc[][21]){
    if(cnt==5){
        int maxnum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(maxnum<bloc[i][j]){
                    maxnum = bloc[i][j];
                        
                }
               // cout <<bloc[i][j] << " ";
            }
          //  cout << "\n";
        }
      //  cout <<"\n";
        if(res<maxnum)
            res = maxnum;
        return;
    }
    for(int i=0;i<4;i++){
        int tmp[21][21];
        for(int p=0;p<n;p++){
            for(int q=0;q<n;q++){
                tmp[p][q] = bloc[p][q];
            }
        }
        if(i==0)
            dfs(cnt+1,pushu(tmp));
        if(i==1)
            dfs(cnt+1,pushd(tmp));
        if(i==2)
            dfs(cnt+1,pushl(tmp));
        if(i==3){
            dfs(cnt+1,pushr(tmp)); 
        }
    }
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin >> tmp;
            maparr[i][j] = tmp;
        }
    }
  //  cout << "\n";
    dfs(0,maparr);
    cout << res;
}
