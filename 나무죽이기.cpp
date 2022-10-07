#include<iostream>
#include<vector>
using namespace std;
int arr[21][21];
int sal[21][21] = {0,};
int n,m,k,c;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int rest;
void treegr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int cnt = 0;
            for(int p=0;p<4;p++){
                int curx = i+dx[p];
                int cury = j+dy[p];
                if(curx>=0&&curx<n&&cury>=0&&cury<n&&arr[curx][cury]>0)
                    cnt++;
            }
            if(arr[i][j]>0){
                arr[i][j]+=cnt;
            }
        }
    }
}
void treese(){
    int tmparr[21][21] = {0,};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]>0){
                int cnt = 0;
                for(int p=0;p<4;p++){
                    int curx = i+dx[p];
                    int cury = j+dy[p];
                    if(curx>=0&&curx<n&&cury>=0&&cury<n&&arr[curx][cury]==0&&sal[curx][cury]==0){                   
                        cnt++;
                    }
                }
                if(cnt!=0){
                    for(int p=0;p<4;p++){
                        int curx = i+dx[p];
                        int cury = j+dy[p];
                        if(curx>=0&&curx<n&&cury>=0&&cury<n&&arr[curx][cury]==0&&sal[curx][cury]==0){
                            tmparr[curx][cury] = tmparr[curx][cury]+ arr[i][j]/cnt;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]+=tmparr[i][j];
        }
    }
}



vector<int> findkill(){
    int x[8] = {1,1,-1,-1};
    int y[8] = {1,-1,1,-1};
    int maxt = 0;
    int maxx=-1,maxy=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmpnum = 0;
            if(arr[i][j]<=0)
                continue;
            if(arr[i][j]>0){
                tmpnum += arr[i][j];
            }
            for(int pi=0;pi<4;pi++){
                for(int pix = 1;pix<=2;pix++){
                    int curx = i+x[pi]*pix;
                    int cury = j+y[pi]*pix;
                    if(curx>=0&&curx<n&&cury>=0&&cury<n){
                        if(arr[curx][cury]<=0)
                            break;
                        if(arr[curx][cury]>0)
                            tmpnum+=arr[curx][cury];
                    }
                }
            }
            if(tmpnum>maxt){
                maxt = tmpnum;
                maxx = i;
                maxy = j;
            }
        }
    }
    vector<int> res;
    res.push_back(maxx);
    res.push_back(maxy);
    return res;
}

void killt(int tx, int ty){
    int x[8] = {1,1,-1,-1};
    int y[8] = {1,-1,1,-1};
    int nowki = 0;
    if(arr[tx][ty]>0){
        nowki = nowki+arr[tx][ty];
    }
    sal[tx][ty]= -c-1;
    arr[tx][ty] = -2;
    for(int i=0;i<4;i++){
        for(int pix = 1;pix<=2;pix++){
            int curx = tx+x[i]*pix;
            int cury = ty+y[i]*pix;
            if(curx>=0&&curx<n&&cury>=0&&cury<n){
                if(arr[curx][cury]<0)
                    break;
                if(arr[curx][cury]>0)
                    nowki+=arr[curx][cury];
                arr[curx][cury] = -2;
                sal[curx][cury] = -c-1;
            }
        }
    }
    rest += nowki;
}

void upd(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sal[i][j]<0){
                sal[i][j]++;
                if(sal[i][j]==0)
                    arr[i][j]=0;
            }
        }
    }
}

int main(){
    rest = 0;
    cin>>n>>m>>k>>c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }
    
    for(int i=0;i<m;i++){
        treegr();
        treese();
        vector<int> k;
        k = findkill();
        if(k[0]==-1){
            break;
        }
        killt(k[0],k[1]);
        upd();
    }
    cout << rest;
}
