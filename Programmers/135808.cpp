// 과일 장수

#include "../Global.h"
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score)
{
    vector<int> apples(k + 1, 0);

    for (const auto& apple : score)
        apples[apple]++;

    int answer = 0;

    for (int idx = (int)apples.size() - 1; idx >= 0; --idx)
    {
        int apple = 0;
        
        while (apples[idx] >= m)
        {
            apple += apples[idx] / m;
            apples[idx] %= m;
        }

        answer += (apple * m * idx);

        if (idx > 0 and apples[idx] > 0)
            apples[idx - 1] += apples[idx];
    }

    return answer;
}

int main()
{
    int k, m;
    vector<int> score;

    k = 3;
    m = 4;
    score = {1, 2, 3, 1, 2, 3, 1};
    cout << solution(k, m, score) << endl;

    k = 4;
    m = 3;
    score = {4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2};
    cout << solution(k, m, score) << endl;

    return 0;
}
