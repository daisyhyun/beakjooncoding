#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id) {
    string answer = "";
    for(int i=0;i<new_id.size();i++){
        if(new_id[i]>='A'&&new_id[i]<='Z')
            new_id[i]+=32;
    }
    cout <<new_id<<" 소문자\n";
    string tmp = "";
    for(int i=0;i<new_id.size();i++){
        if((new_id[i]>='a'&&new_id[i]<='z')||new_id[i]=='-'||new_id[i]=='_'||new_id[i]=='.'||(new_id[i]>=48&&new_id[i]<=57)){
            tmp+=new_id[i];
        }
    }
    cout <<tmp<<" 잡문자제거\n";
    string tmp1 = "";
    tmp1+=tmp[0];
    for(int i=1;i<tmp.size();i++){
        if(tmp[i-1]=='.'&&tmp[i]=='.')
            continue;
        tmp1+=tmp[i];
    }
    cout << tmp1 <<" . 이중제거\n";
    string tmp2 = "";
    if(tmp1[0]=='.'){
        for(int i=1;i<tmp1.size();i++)
            tmp2+=tmp1[i];
    }
    else{
        for(int i=0;i<tmp1.size();i++)
            tmp2+=tmp1[i];
    }
    cout << tmp2<<" 앞.제거\n";
    string tmp3 = "";
    if(tmp2[tmp2.size()-1]=='.'){
        for(int i=0;i<tmp2.size()-1;i++)
            tmp3+=tmp2[i];
    }
    else{
        tmp3 = tmp2;
    }
    cout <<tmp3 <<" 뒤.제거\n";
    if(tmp3.size()==0){
        tmp3+='a';
    }
    cout << tmp3 <<" 사이즈0일시 a추가\n";
    string tmp4 = "";
    if(tmp3.size()>=16){
        if(tmp3[14]=='.'){
            for(int i=0;i<14;i++)
                tmp4+=tmp3[i];
        }
        else{
            for(int i=0;i<15;i++)
                tmp4+=tmp3[i];
        }
    }
    else{
        for(int i=0;i<tmp3.size();i++)
            tmp4+=tmp3[i];
    }
    if(tmp4.size()<=2){
        int tmpsize = tmp4.size();
        cout << tmp4[tmpsize-1] << " 추가될 문자\n";
        while(tmp4.size()<3){
            tmp4+=tmp4[tmpsize-1];
        }
    }
    answer = tmp4;
    return answer;
}
