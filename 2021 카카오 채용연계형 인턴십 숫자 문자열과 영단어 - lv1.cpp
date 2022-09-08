#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    string tmp ="";
    string num="";
    string word[10] = {"zero","one","two","three","four","five","six","seven",
                      "eight","nine"};
    for(int i=0;i<s.size();i++){
        if(s[i]>=48&&s[i]<=57)
            tmp += s[i];
        else{
            num+=s[i];
            if(num.size()>=3){
                for(int j=0;j<10;j++){
                    if(word[j].compare(num)==0){
                        tmp+= to_string(j);
                        num = "";
                        break;
                    }
                }
            }
                
        }
    }
    int pow = 1;
    for(int i=tmp.size()-1;i>=0;i--){
        answer+=(tmp[i]-48)*pow;
        pow *=10;
    }
    return answer;
}
