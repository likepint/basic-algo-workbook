// 유기농 배추

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define Y first
#define X second
#define endl '\n'

int T, M, N, K;

vector<vector<bool>> Field, Visited;

vector<pair<int, int>> Direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void SetField()
{
    cin >> M >> N >> K;

    Field = Visited = vector<vector<bool>>(M, vector<bool>(N, false));

    while (K-- > 0)
    {
        int y, x;
        cin >> y >> x;

        Field[y][x] = true;
    }
}

void BFS(queue<pair<int, int>>& InQ)
{
    while (!InQ.empty())
    {
        int cy = InQ.front().Y;
        int cx = InQ.front().X;

        InQ.pop();

        for (const auto& d : Direction)
        {
            int ny = cy + d.Y;
            int nx = cx + d.X;

            if (0 > ny or ny >= M)
                continue;

            if (0 > nx or nx >= N)
                continue;

            if (Visited[ny][nx])
                continue;

            if (!Field[ny][nx])
                continue;

            InQ.emplace(ny, nx);
            Visited[ny][nx] = true;
        } // for Direction
    } // while !InQ.empty()
}

void Print(const int& InResult)
{
    cout << InResult << endl;
}

void Solution()
{
    cin >> T;

    while (T-- > 0)
    {
        SetField();

        int result = 0;

        for (int y = 0; y < M; ++y)
        {
            for (int x = 0; x < N; ++x)
            {
                if (!Visited[y][x] and Field[y][x])
                {
                    Visited[y][x] = true;
                    
                    queue<pair<int, int>> q;
                    q.emplace(y, x);
                    
                    BFS(q);

                    result++;
                }
            } // for x
        } // for y

        Print(result);
    } // while T
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Solution();

    return 0;
}
