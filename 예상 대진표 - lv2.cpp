#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int cnt =0;
    while(a!=b){
        a = (a+1)/2;
        b = (b+1)/2;
        cnt++;
    }
    return cnt;
}
