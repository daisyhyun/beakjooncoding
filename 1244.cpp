#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n;
int arr[101];
int student;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cin>>student;
    for(int i=0;i<student;i++){
        int gender, num;
        cin>>gender>>num;
        if(gender==1){
            for(int j=num;j<=n;){
                if(arr[j]==0)
                    arr[j]=1;
                else
                    arr[j]=0;
                j+=num;
            }
        }
        else{
            int check = 0;
            while(1){
                if(num-check<=0||num+check>n){
                    break;
                }
                if(arr[num-check]==arr[num+check]){
                    check++;
                }
                else
                {
                    break;
                }
                
            }
            check--;
            for(int k=num-check;k<=num+check;k++){
                if(arr[k]==0)
                    arr[k]=1;
                else   
                    arr[k]=0;
            }
        }
    

    }
     for(int i=1;i<=n;i++){
        cout << arr[i] <<" ";
        if(i%20==0)
            cout << "\n";
       
     }
}
