#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int fir = 0;
    for(int i=0;i<s.length();i++){
        if(fir==0&&!isspace(s[i])){
            fir = 1;
            if(s[i]>='a'&&s[i]<='z')
                s[i] = s[i] - 'a' + 'A';
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            s[i] = s[i] - 'A' + 'a';
        }
        else if(isspace(s[i])){
            fir = 0;
        }
    }
    answer = s;
    return answer;
}
