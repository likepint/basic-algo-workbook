#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

int CalculateCost(const vector<int>& InPacks)
{
    priority_queue<int, vector<int>, greater<int>> heap(InPacks.begin(), InPacks.end());

    int totalCost = 0;

    while (heap.size() > 1)
    {
        int first = heap.top();
        heap.pop();

        int second = heap.top();
        heap.pop();

        int merged = first + second;
        totalCost += merged;

        heap.push(merged);
    }

    return totalCost;
}

int main()
{
    int N;
    cin >> N;

    vector<int> packs(N);
    for (int& card : packs)
        cin >> card;

    cout << CalculateCost(packs) << endl;

    return 0;
}
