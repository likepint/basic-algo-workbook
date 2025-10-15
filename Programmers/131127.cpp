// 할인 행사

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

#define endl '\n'

int solution(vector<string> want, vector<int> number, vector<string> discount)
{
    unordered_map<string, int> wanted;
    for (int idx = 0; idx < (int)want.size(); ++idx)
        wanted[want[idx]] = number[idx];

    int answer = 0;

    unordered_map<string, int> purchased;

    for (int i = 0; i < (int)discount.size(); ++i)
    {
        if (i >= 10)
        {
            if (--purchased[discount[i - 10]] <= 0)
                purchased.erase(discount[i - 10]);
        }

        purchased[discount[i]]++;

        if (wanted == purchased)
            answer++;
    }

    return answer;
}

int main()
{
    vector<string> want, discount;
    vector<int> number;

    want = { "banana", "apple", "rice", "pork", "pot" };
    number = { 3, 2, 2, 2, 1 };
    discount = { "chicken", "apple", "apple", "banana", "rice", "apple", "pork", "banana", "pork", "rice", "pot", "banana", "apple", "banana" };

    cout << solution(want, number, discount) << endl;

    want = { "apple" };
    number = { 10 };
    discount = { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" };

    cout << solution(want, number, discount) << endl;

    return 0;
}
