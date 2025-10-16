// 기사단원의 무기

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int solution(int number, int limit, int power)
{
    vector<int> divisors(number + 1, 0);

    for (int i = 1; i <= number; ++i)
    {
        for (int k = i; k <= number; k += i)
            divisors[k]++;
    }

    int answer = 0;

    for (int i = 1; i < (int)divisors.size(); ++i)
    {
        if (divisors[i] > limit)
            divisors[i] = power;

        answer += divisors[i];
    }

    return answer;
}

int main()
{
    int number, limit, power;

    number = 5;
    limit = 3;
    power = 2;
    cout << solution(number, limit, power) << endl;

    number = 10;
    limit = 3;
    power = 2;
    cout << solution(number, limit, power) << endl;

    return 0;
}
