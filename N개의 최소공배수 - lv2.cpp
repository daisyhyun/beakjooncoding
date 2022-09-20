#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int size = arr.size();
    int left = arr[0];
    for(int i=1;i<size;i++){
        int right = arr[i];
        int tmpl = left;
        int tmpr = right;
        while(tmpl!=tmpr){
            if(tmpr>tmpl){
                tmpl+=left;
            }
            else{
                tmpr+=right;
            }
        }
        left = tmpr;
    }
    return left;
}
