// 더 맵게

#include "../Global.h"
#include <vector>
#include <queue>

using namespace std;

#define endl '\n'

int solution(vector<int> scoville, int K)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq(scoville.begin(), scoville.end());

    int answer = 0;

    while (pq.size() > 1 and pq.top() < K)
    {
        long long first = pq.top();
        pq.pop();
        
        long long second = pq.top();
        pq.pop();

        pq.push(first + second * 2);
        answer++;
    }

    if (pq.top() < K)
        return -1;
    else return answer;
}

int main()
{
    vector<int> scoville;
    int K = 0;

    scoville = {1, 2, 3, 9, 10, 12};
    K = 7;

    cout << solution(scoville, K) << endl;
    
    return 0;
}
