#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

template<typename T>
void Print(const T& InNumber)
{
    cout << InNumber << endl;
}

template<typename T>
void Print(const vector<T>& InList)
{
    for (const auto& list : InList)
        cout << list << " ";

    cout << endl;
}
