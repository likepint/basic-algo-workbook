// 그림

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define Y first
#define X second
#define endl '\n'

int Height, Width;

vector<vector<int>> Canvas; // 캔버스

vector<pair<int, int>> Direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 방향

vector<int> Result; // Result.size() == 그림의 갯수, 오름차순 정렬 Result.back() == 가장 큰 그림의 크기

void MakeCanvas()
{
    cin >> Height >> Width;

    Canvas = vector<vector<int>>(Height, vector<int>(Width, 0));

    for (int y = 0; y < Height; ++y)
    {
        for (int x = 0; x < Width; ++x)
            cin >> Canvas[y][x];
    }
}

void BFS(queue<pair<int, int>>& InQ)
{
    while (!InQ.empty())
    {
        int cy = InQ.front().Y;
        int cx = InQ.front().X;

        InQ.pop();

        for (const auto& direction : Direction)
        {
            int ny = cy + direction.Y;
            int nx = cx + direction.X;

            if (0 > ny or ny >= Height)
                continue;

            if (0 > nx or nx >= Width)
                continue;

            if (Canvas[ny][nx] == 1)
            {
                Canvas[ny][nx] = 0;
                Result.back() += 1; // 크기 증가
                InQ.emplace(ny, nx);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    MakeCanvas();

    for (int y = 0; y < Height; ++y)
    {
        for (int x = 0; x < Width; ++x)
        {
            if (Canvas[y][x] == 1)
            {
                Canvas[y][x] = 0;
                
                Result.emplace_back(1); // 그림 갯수 추가
                
                queue<pair<int, int>> q;
                q.emplace(y, x);

                BFS(q);
            }
        }
    }

    if (Result.empty())
    {
        cout << 0 << endl;
        cout << 0 << endl;
    }
    else
    {
        sort(Result.begin(), Result.end()); // 오름차순 정렬

        cout << Result.size() << endl;
        cout << Result.back() << endl;
    }

    return 0;
}
