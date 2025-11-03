// 뒤에 있는 큰 수 찾기

#include "../Global.h"
#include <vector>
#include <stack>

using namespace std;

#define endl '\n'

vector<int> solution(vector<int> numbers)
{
    vector<int> answer(numbers.size(), -1);
    
    stack<int> bigger;

    for (int idx = (int)numbers.size() - 1; idx >= 0; --idx)
    {
        while (!bigger.empty() and bigger.top() <= numbers[idx])
            bigger.pop();
        
        if (!bigger.empty())
            answer[idx] = bigger.top();

        bigger.push(numbers[idx]);
    }
    
    return answer;
}

int main()
{
    vector<int> numbers;

    numbers = {2, 3, 3, 5};
    Print(solution(numbers));

    numbers = {9, 1, 5, 3, 6, 2};
    Print(solution(numbers));

    return 0;
}
