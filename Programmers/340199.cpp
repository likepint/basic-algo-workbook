// [PCCE 기출문제] 9번 / 지폐 접기

#include "../Global.h"
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill)
{
    sort(wallet.begin(), wallet.end());
    sort(bill.begin(), bill.end());

    int answer = 0;

    while (bill[0] > wallet[0] or bill[1] > wallet[1])
    {
        if (bill[0] > bill[1])
            bill[0] /= 2;
        else bill[1] /= 2;

        answer++;
        sort(bill.begin(), bill.end());
    }

    return answer;
}

int main()
{
    vector<int> wallet, bill;

    wallet = {30, 15};
    bill = {26, 17};
    cout << solution(wallet, bill) << endl;

    wallet = {50, 50};
    bill = {100, 241};
    cout << solution(wallet, bill) << endl;

    return 0;
}
