#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int n;
queue<int> q;

void Excute()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i)
		q.push(i);

	while (q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << endl;
}

int main()
{
	Excute();

	return 0;
}