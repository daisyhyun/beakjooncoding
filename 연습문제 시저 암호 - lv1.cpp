#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i=0;i<s.length();i++){
        if(s[i]>='a'&&s[i]<='z'){
            s[i]+n<='z' ? s[i]+=n : s[i] = s[i]+n-'z'+'a'-1;
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            s[i]+n<='Z' ? s[i]+=n : s[i] = s[i]+n-'Z'+'A'-1;
      
        }
        
    }
    return s;
}
