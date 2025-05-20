#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define endl '\n'

vector<int> solution(vector<int> InPrices)
{
    vector<int> answer(InPrices.size());

    stack<int> s;

    for (int i = 0; i < answer.size(); ++i)
    {
        while (!s.empty() and InPrices[s.top()] > InPrices[i])
        {
            int topIndex = s.top();
            s.pop();

            answer[topIndex] = i - topIndex;
        }

        s.push(i);
    }

    // 남아있는 인덱스들은 끝까지 떨어지지 않은 경우
    while (!s.empty())
    {
        int topIndex = s.top();
        s.pop();

        answer[topIndex] = answer.size() - 1 - topIndex;
    }

    return answer;
}

void print(const vector<int>& InResult)
{
    for (const auto& result : InResult)
        cout << result << " ";

    cout << endl;
}

int main()
{
    vector<int> prices = { 1, 2, 3, 2, 3 };

    vector<int> result = solution(prices);

    print(result);

    return 0;
}