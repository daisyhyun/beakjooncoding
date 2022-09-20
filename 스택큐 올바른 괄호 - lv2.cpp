#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int strlen = s.length();
    int left = 0;
    for(int i=0;i<strlen;i++){
        if(s[i]=='('){
            left++;
        }
        else{
            left--;
        }
        if(left<0)
            return false;
    }
    if(left!=0)
        return false;
    return true;
}
