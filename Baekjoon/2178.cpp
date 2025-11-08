// 미로 탐색

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define Y first
#define X second
#define endl '\n'

int Height, Width;

vector<vector<char>> Field;

vector<pair<int, int>> Direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void SetField()
{
    cin >> Height >> Width;

    Field = vector<vector<char>>(Height, vector<char>(Width));
    for (int y = 0; y < Height; ++y)
    {
        for (int x = 0; x < Width; ++x)
            cin >> Field[y][x];
    } // for y
}

int BFS(queue<tuple<int, int, int>>& InQ)
{
    while (!InQ.empty())
    {
        int cy, cx, distance;
        tie(cy, cx, distance) = InQ.front();

        InQ.pop();

        for (const auto& dir : Direction)
        {
            int ny = cy + dir.Y;
            int nx = cx + dir.X;

            if (0 > ny or ny >= Height)
                continue;

            if (0 > nx or nx >= Width)
                continue;

            if (Field[ny][nx] == '1')
            {
                if (ny == Height - 1 and nx == Width - 1)
                    return distance + 1;

                Field[ny][nx] = '0';

                InQ.emplace(ny, nx, distance + 1);
            }
        }
    }
}

void MazeExploration()
{
    SetField();

    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 1);
    Field[0][0] = '0';

    cout << BFS(q) << endl;
}

int main()
{
    MazeExploration();

    return 0;
}
