// 수들의 합 2

#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

struct Element
{
    int N;
    long long M;
    vector<int> Array;
};

long long TwoPointers(Element& InElement)
{
    long long current = 0, answer = 0;
    int start = 0;

    for (int end = 0; end < InElement.N; ++end)
    {
        current += InElement.Array[end];

        while (start <= end and current > InElement.M)
        {
            current -= InElement.Array[start];
            start++;
        }

        if (current == InElement.M)
            answer++;
    }

    return answer;
}

void solution()
{
    Element element;

    cin >> element.N >> element.M;

    element.Array = vector<int>(element.N, 0);
    for (auto& value : element.Array)
        cin >> value;

    cout << TwoPointers(element) << endl;
}

int main()
{
    solution();
    
    return 0;
}
