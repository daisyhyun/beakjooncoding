#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
#define MAX 100000
int main(){
    int n,s;
    int arr[MAX];
    int start = 0;
    int end = 0;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int tmpsum=arr[0];
    int minlen = 100001;
    while(start<=end&&end!=n){
        if(tmpsum>=s){
            tmpsum-=arr[start];
            minlen = min(minlen,end-start+1);
            start++;
            
        }
        else{
            end++;
            tmpsum+=arr[end];
        }
    }
    if(minlen==100001)
        cout << 0;
    else
        cout << minlen;
}
