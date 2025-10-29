// SumX

#include "../Global.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

struct Element
{
    int n = 0;
    vector<int> Integers;
    int x = 0;
    int answer = 0;
};

int TwoPointers(Element& InElement)
{
    sort(InElement.Integers.begin(), InElement.Integers.end());

    int left = 0, right = (int)InElement.Integers.size() - 1;

    while (left < right)
    {
        const int& current = InElement.Integers[left] + InElement.Integers[right];

        if (current < InElement.x)
        {
            left++;
        }
        else if (current > InElement.x)
        {
            right--;
        }
        else if (current == InElement.x)
        {
            left++;
            right--;
            
            InElement.answer++;
        }
    }

    return InElement.answer;
}

void solution()
{
    Element element;

    cin >> element.n;

    element.Integers = vector<int>(element.n, 0);
    for (int idx = 0; idx < element.n; ++idx)
        cin >> element.Integers[idx];

    cin >> element.x;

    cout << TwoPointers(element) << endl;
}

int main()
{
    solution();

    return 0;
}
