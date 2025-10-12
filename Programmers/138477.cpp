// 명예의 전당 (1)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;

    priority_queue<int, vector<int>, greater<int>> Honors;

    for (int i = 0; i < score.size(); ++i)
    {        
        Honors.push(score[i]);

        if (Honors.size() > k)
            Honors.pop();
            
        answer.emplace_back(Honors.top());
    }

    return answer;
}

int main()
{
    int k = 4;
    vector<int> score = { 0, 300, 40, 300, 20, 70, 150, 50, 500, 1000 };

    vector<int> answer = solution(k, score);
    for (const auto& scores : answer)
        cout << scores << endl;

    return 0;
}
