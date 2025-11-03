#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

inline void Print(const vector<int>& InList)
{
    for (const auto& list : InList)
        cout << list << " ";

    cout << endl;
}
