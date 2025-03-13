#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define endl '\n'

vector<pair<int, int>> direction =
{
	{+2, -1}, {+2, +1},
	{+1, +2}, {-1, +2},
	{-2, +1}, {-2, -1},
	{-1, -2}, {+1, -2}
};

void Print(const vector<int>& result)
{
	for (auto& idx : result)
		cout << idx << endl;

	cout << endl;
}

int bfs(vector<vector<bool>>& chess, const pair<int, int>& start, const pair<int, int>& dest)
{
	vector<vector<bool>> visited = chess; // 방문 배열

	// { { 시작 X, 시작Y }, 이동 횟수 }
	queue<pair<pair<int, int>, int>> q;

	// 시작점을 방문 처리 후, 큐에 추가
	chess[start.X][start.Y] = 1;
	q.push({ { start.X, start.Y }, 0 });

	while (!q.empty())
	{
		int cx = q.front().first.X; // 현재 x 좌표
		int cy = q.front().first.Y; // 현재 y 좌표

		int step = q.front().second; // 현재 위치까지의 이동 횟수

		q.pop();

		for (size_t i = 0; i < direction.size(); ++i)
		{
			int nx = cx + direction[i].X; // 다음 x 좌표
			int ny = cy + direction[i].Y; // 다음 y 좌표

			if (0 > nx or nx >= chess.size()) // x의 범위 체크
				continue;

			if (0 > ny or ny >= chess[0].size()) // y의 범위 체크
				continue;

			if (visited[nx][ny]) continue; // 방문여부 체크

			if (nx == dest.X and ny == dest.Y) // 다음 좌표가 도착점인지 체크
				return step + 1; // 도착점이라면 현재의 이동 횟수에 +1 후 리턴

			q.push({ {nx, ny}, step + 1 }); // 다음 좌표와 이동 횟수 +1 리턴
			visited[nx][ny] = 1; // 방문 처리
		} // for i
	} // while (!q.empty())

	return 0;
}

vector<int> excute(int cnt)
{
	vector<int> result;

	for (size_t i = 0; i < cnt; ++i)
	{
		// 체스판 한변의 길이, 시작점x, 시작점y, 도착점x, 도착점y
		int size, cx, cy, dx, dy;
		cin >> size >> cx >> cy >> dx >> dy;

		vector<vector<bool>> chess(size, vector<bool>(size, 0));

		pair<int, int> start = { cx, cy };
		pair<int, int> dest = { dx, dy };

		if (start == dest) // 시작점과 도착점이 같다면
		{
			// 이동할 필요가 없으므로 결과 값 0을 추가 후 continue;
			result.emplace_back(0);

			continue;
		}

		// bfs 함수 종료 시 반환하는 이동 횟수를 result에 추가
		result.emplace_back(bfs(chess, start, dest));
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;
	cin >> cnt;

	vector<int> result = excute(cnt);

	Print(result);

	return 0;
}