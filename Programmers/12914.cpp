// 멀리 뛰기

#include "../Global.h"
#include <vector>

using namespace std;

long long solution(int n)
{
    if (n <= 3)
        return n;

    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; ++i)
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1234567;

    return dp.back();
}

int main()
{
    int n = 0;

    n = 4;
    cout << solution(n) << endl;

    n = 3;
    cout << solution(n) << endl;

    return 0;
}
