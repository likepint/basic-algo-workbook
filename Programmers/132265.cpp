// 롤케이크 자르기

#include "../Global.h"

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> toppings)
{
    unordered_map<int, int> older, younger;

    for (const auto& topping : toppings)
        younger[topping]++;

    int answer = 0;

    for (const auto& topping : toppings)
    {
        older[topping]++;

        if (--younger[topping] <= 0)
            younger.erase(topping);

        if (older.size() == younger.size())
            answer++;
    }

    return answer;
}

int main()
{
    vector<int> topping;

    topping = {1, 2, 1, 3, 1, 4, 1, 2};
    cout << solution(topping) << endl;

    topping = {1, 2, 3, 1, 4};
    cout << solution(topping) << endl;

    return 0;
}
