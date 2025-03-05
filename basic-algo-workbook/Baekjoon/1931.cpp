#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

bool CompareFirst(pair<int, int> pair1, pair<int, int> pair2)
{
    return pair1.first < pair2.first;
}

bool CompareSecond(pair<int, int> pair1, pair<int, int> pair2)
{
    return pair1.second < pair2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    size_t n = 0;
    cin >> n;

    vector<pair<int, int>> meetings;

    for (size_t i = 0; i < n; ++i)
    {
        int st, et;
        cin >> st >> et;

        meetings.push_back({ st, et });
    }

    sort(meetings.begin(), meetings.end(), CompareFirst);
    sort(meetings.begin(), meetings.end(), CompareSecond);

    int end = meetings[0].second;
    int cnt = 1;

    for (size_t i = 1; i < meetings.size(); ++i)
    {
        if (end <= meetings[i].first)
        {
            cnt++;

            end = meetings[i].second;
        }
    }

    cout << cnt << endl;

    return 0;
}