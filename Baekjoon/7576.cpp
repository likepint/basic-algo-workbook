// 토마토

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Y first
#define X second
#define endl '\n'

int Width, Height, ZeroCnt, Days = -1; // 가로, 세로, 0의 갯수, 걸리는 기간
vector<vector<int>> Box;
queue<pair<int, int>> Q;
vector<pair<int, int>> Direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 방향

void MakeBox() // 박스 크기 생성
{
    cin >> Width >> Height;

    Box = vector<vector<int>>(Height, vector<int>(Width));

    for (int y = 0; y < Height; ++y)
    {
        for (int x = 0; x < Width; ++x)
        {
            cin >> Box[y][x];

            if (Box[y][x] == 0) // 0의 갯수
                ZeroCnt++;
            else if (Box[y][x] == 1) // 1의 좌표
                Q.push({y, x});
        }
    }
}

void BFS()
{
    vector<vector<int>> visited = Box;

    while (!Q.empty())
    {
        Days++;

        int size = (int)(Q.size()); // 하루를 계산하기 위한 q 사이즈

        while (size-- > 0)
        {
            int cy = Q.front().Y;
            int cx = Q.front().X;

            Q.pop();

            for (const auto& dir : Direction)
            {
                int ny = cy + dir.Y;
                int nx = cx + dir.X;

                if (0 > ny or ny >= Height)
                    continue;

                if (0 > nx or nx >= Width)
                    continue;

                if (visited[ny][nx] == 1)
                    continue;

                if (Box[ny][nx] != 0)
                    continue;

                visited[ny][nx] = 1;

                Box[ny][nx] = 1;

                ZeroCnt--; // 0의 갯수 차감

                Q.push({ny, nx});
            }
        }
    }
}

void Print()
{
    if (ZeroCnt == 0)
        cout << Days << endl;
    else cout << -1 << endl;
}

void solution()
{
    MakeBox();

    BFS();

    Print();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solution();

    return 0;
}
