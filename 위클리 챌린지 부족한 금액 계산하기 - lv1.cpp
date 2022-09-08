using namespace std;

long long solution(int price, int money, int count)
{
    int answer = -1;
    int pr = price;
    long long sumpr = 0;
    for(int i=1;i<=count;i++){
        sumpr+=pr;
        pr+=price;
    }
    if(sumpr>money)
        return sumpr-money;
    else
        return 0;
}
