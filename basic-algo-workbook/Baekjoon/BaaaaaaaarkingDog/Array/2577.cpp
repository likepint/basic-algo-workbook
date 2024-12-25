#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Input()
{
	int ret = 1, temp = 0;

	for (size_t i = 0; i < 3; ++i)
	{
		cin >> temp;

		ret *= temp;
	}

	return ret;
}

void print(const vector<int>& InResult)
{
#define endl '\n'
	for (const auto& idx : InResult)
		cout << idx << endl;
#undef endl
}

void Execute()
{
	int num = Input();

	vector<int> ret(10, 0);

	for (const auto& idx : to_string(num))
		ret[idx - '0'] += 1;

	print(ret);
}

int main()
{
	Execute();

	return 0;
}