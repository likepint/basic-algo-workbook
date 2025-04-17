#include <iostream>
#include <queue>

using namespace std;

#define endl '\n'

int n, num;
string oper;
queue<int> q;

void Excute()
{
	cin >> oper;

	if (oper == "push")
	{
		cin >> num;

		q.push(num);
	}
	else if (oper == "pop")
	{
		if (!q.empty())
		{
			cout << q.front() << endl;

			q.pop();
		}
		else cout << -1 << endl;
	}
	else if (oper == "front")
	{
		if (q.empty())
			cout << -1 << endl;
		else cout << q.front() << endl;
	}
	else if (oper == "back")
	{
		if (q.empty())
			cout << -1 << endl;
		else cout << q.back() << endl;
	}
	else if (oper == "size")
		cout << q.size() << endl;
	else if (oper == "empty")
		cout << (int)q.empty() << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		Excute();

	return 0;
}