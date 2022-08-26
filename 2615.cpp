#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[20][20];
vector<pair<int,int> > blac;
vector<pair<int,int> > whit;
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};
int main(){
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin >> arr[i][j];
            if(arr[i][j]==1)
                blac.push_back(make_pair(i,j));
            else if(arr[i][j]==2)
                whit.push_back(make_pair(i,j));
        }
    }
    while(!blac.empty()){
        for(int i=0;i<8;i++){
            int cnt = 1;
            int x = blac.front().first;
            int y = blac.front().second;
            int p = (i+4)%8;
            if(arr[x+dx[p]][y+dy[p]]==1){
                continue;
            }
            while(1){
                x+=dx[i];
                y+=dy[i];
                if(x<0||x>=19||y<0||y>=19)
                    break;
                if(arr[x][y]!=1)
                    break;
                cnt++;
            }
            if(cnt==5){
                int tmpx = blac.front().first;
                int tmpy = blac.front().second;
                if(dy[i]<0){
                    tmpx += dx[i]*4;
                    tmpy += dy[i]*4;
                }
                cout << 1 << "\n" <<  tmpx+1 << " " <<tmpy+1;
                return 0;
            }
        }
        blac.erase(blac.begin());
    }
    while(!whit.empty()){
        for(int i=0;i<8;i++){
            int cnt = 1;
            int x = whit.front().first;
            int y = whit.front().second;
            int p = (i+4)%8;
            if(arr[x+dx[p]][y+dy[p]]==2){
                continue;
            }
            while(1){
                x+=dx[i];
                y+=dy[i];
                if(x<0||x>=19||y<0||y>=19)
                    break;
                if(arr[x][y]!=2)
                    break;
                cnt++;
            }
            if(cnt==5){
                int tmpx = whit.front().first;
                int tmpy = whit.front().second;
                if(dy[i]<0){
                    tmpx += dx[i]*4;
                    tmpy += dy[i]*4;
                }
                cout << 2 << "\n" <<  tmpx+1 << " " <<tmpy+1;
                return 0;
            }
        }
        whit.erase(whit.begin());
    }
    cout << 0;
}
