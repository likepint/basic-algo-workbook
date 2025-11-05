// 게임 맵 최단 거리

#include "../Global.h"
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define endl '\n'
#define X first
#define Y second

int BFS(const vector<vector<int>>& InMaps, const vector<pair<int, int>>& InDirection)
{
    int height = (int)InMaps.size();
    int width = (int)InMaps[0].size();

    vector<vector<bool>> visited(height, vector<bool>(width, false));

    queue<tuple<int, int, int>> q;
    q.push({0, 0, 1});
    visited[0][0] = true; // 방문 처리

    while (!q.empty())
    {
        int cy, cx, distance;
        tie(cy, cx, distance) = q.front();
        q.pop();

        // 다음 이동 가능한 좌표 순회
        for (int idx = 0; idx < (int)InDirection.size(); ++idx)
        {
            int ny = cy + InDirection[idx].Y;
            int nx = cx + InDirection[idx].X;

            if (ny == height - 1 and nx == width - 1)
                return distance + 1; // 상대방 진영(우측 하단)

            if (0 > ny or ny >= height)
                continue;

            if (0 > nx or nx >= width)
                continue;

            // 벽이거나 이미 방문했던 좌표라면
            if (InMaps[ny][nx] == 0 or visited[ny][nx])
                continue;

            q.push({ny, nx, distance + 1});
            visited[ny][nx] = true; // 방문 처리
        } // for direction
    } // while q

    return -1; // 도착 불가능한 곳이라면 -1
}

int solution(vector<vector<int>> InMaps)
{
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    return BFS(InMaps, direction);
}

int main()
{
    vector<vector<int>> maps;

    maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
    cout << solution(maps) << endl;

    maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 0}, {0, 0, 0, 0, 1}};
    cout << solution(maps) << endl;

    return 0;
}
