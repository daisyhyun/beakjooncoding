#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int tc=1;tc<=n;tc++){
        string tmp;
        cin>>tmp;
        int res=0;
        for(int i=0;i<tmp.length();i++){
            if(tmp[i]=='(')
                res++;
            else{
                res--;
            }
            if(res<0)
                break;
        }
        if(res==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

}
