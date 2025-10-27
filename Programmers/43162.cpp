// 네트워크

#include "../Global.h"
#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& computers, vector<bool>& visited, const int& n, int start)
{
    visited[start] = true;

    for (int idx = 0; idx < n; ++idx) // 현재 노드와 연결된 다른 모든 노드를 확인
    {
        // 연결되어 있고(computers[start][i] == 1) 아직 방문하지 않았다면(visited[i] == false)
        if (computers[start][idx] == 1 and !visited[idx])
        {
            // 재귀적으로 탐색
            dfs(computers, visited, n, idx);
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    vector<bool> visited(n, false);

    int network = 0;

    for (int idx = 0; idx < n; ++idx)
    {
        if (visited[idx])
            continue;

        network++;
        dfs(computers, visited, n, idx);
    }

    return network;
}

int main()
{
    int n = 0;
    vector<vector<int>> computers;

    n = 3;
    computers =
    {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << solution(n, computers) << endl;

    n = 3;
    computers =
    {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };
    cout << solution(n, computers) << endl;

    return 0;
}
