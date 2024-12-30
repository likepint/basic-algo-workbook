#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

vector<int> Input()
{
	unsigned n = 0;
	cin >> n;

	vector<int> sequence(n, 0);

	for (auto& index : sequence)
		cin >> index;

	sort(sequence.begin(), sequence.end());

	return sequence;
}

void Execute()
{
	vector<int> sequence = Input();

	unsigned x = 0;
	cin >> x;

	unsigned start = 0, finish, result = 0;

	finish = sequence.size() - 1;

	while (start < finish)
	{
		if (sequence[start] + sequence[finish] > x)
		{
			finish--;

			continue;
		}

		if (sequence[start] + sequence[finish] < x)
		{
			start++;

			continue;
		}

		if (sequence[start] + sequence[finish] == x)
		{
			start++, finish--;

			result++;

			continue;
		}
	}

	cout << result << endl;
}

int main()
{
	Execute();

	return 0;
}