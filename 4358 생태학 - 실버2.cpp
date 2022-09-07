#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    map<string,int> arr;
    int cnt=0;
    string s;
    while(getline(cin, s)) {
        arr[s]++;
        cnt++;
    }
    cout <<fixed;
    cout.precision(4);
    for(auto tmp = arr.begin();tmp!=arr.end();tmp++) {
        cout << tmp->first << ' ' << round(tmp->second/(double)cnt*1000000)/10000 << '\n';
    }
    return 0;
}
