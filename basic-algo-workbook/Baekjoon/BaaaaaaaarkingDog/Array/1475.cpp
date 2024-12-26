#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string Input()
{
	string room = "";
	cin >> room;

	return room;
}

void Print(unordered_map<int, int> unmap)
{
#define endl '\n'
	int ret = 0;

	for (auto it = unmap.begin(); it != unmap.end(); ++it)
	{
		if (it->first == 6)
		{
			ret = max(ret, it->second / 2 + it->second % 2);

			continue;
		}

		ret = max(ret, it->second);
	}

	cout << ret << endl;
#undef endl
}

void Execute()
{
	string room = Input();

	unordered_map<int, int> unmap;

	for (const auto& idx : room)
	{
		int ctoi = idx - '0';

		if (ctoi == 9)
		{
			unmap[6]++;

			continue;
		}

		unmap[ctoi]++;
	}

	Print(unmap);
}

int main()
{
	Execute();

	return 0;
}