#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define endl '\n'

struct Extent
{
	int w = 0;
	int h = 0;
};

int result, cnt;

int main()
{
	Extent extent;

	cin >> extent.w >> extent.h;

	vector<vector<int>> canvas(extent.w, vector<int>(extent.h, 0));

	vector<vector<bool>> visited(extent.w, vector<bool>(extent.h, 0));

	for (int i = 0; i < extent.w; ++i)
	{
		for (int j = 0; j < extent.h; ++j)
		{
			cin >> canvas[i][j];

			visited[i][j] = canvas[i][j];
		}
	}

	vector<pair<int, int>> direction = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

	for (int i = 0; i < canvas.size(); ++i)
	{
		for (int j = 0; j < canvas[i].size(); ++j)
		{
			queue<pair<int, int>> q;

			if (canvas[i][j] == 1 and visited[i][j] == 1)
			{
				q.push({ i, j });

				visited[i][j] = 0;

				int size = 1;

				while (!q.empty())
				{
					int x = q.front().X;
					int y = q.front().Y;

					q.pop();

					for (size_t i = 0; i < direction.size(); ++i)
					{
						int nx = x + direction[i].X;
						int ny = y + direction[i].Y;

						if (0 > nx or nx >= extent.w)
							continue;

						if (0 > ny or ny >= extent.h)
							continue;

						if (visited[nx][ny] == 0)
							continue;

						q.push({ nx, ny });

						visited[nx][ny] = 0;

						size += 1;
					}
				} // while (!q.empty())

				cnt++;

				result = max(result, size);
			} // if (canvas[i][j] == 1 and visited[i][j] == 1)
		} // for j
	} // for i

	cout << cnt << endl << result << endl;

	return 0;
}