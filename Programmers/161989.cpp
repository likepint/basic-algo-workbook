// 덧칠하기

#include "../Global.h"
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section)
{
    int painted = section[0] + m - 1;
    int answer = 1;

    for (const auto& wall : section)
    {
        if (wall > painted)
        {
            answer++;
            painted = wall + m - 1;
        }
    }

    return answer;
}

int main()
{
    int n = 0, m = 0;
    vector<int> section = vector<int>();

    n = 8;
    m = 4;
    section = {2, 3, 6};
    cout << solution(n, m, section) << endl;

    n = 5;
    m = 4;
    section = {1, 3};
    cout << solution(n, m, section) << endl;

    n = 4;
    m = 1;
    section = {1, 2, 3, 4};
    cout << solution(n, m, section) << endl;

    return 0;
}
