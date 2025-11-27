// Keylogger

#include <iostream>
#include <list>
#include <string>

using namespace std;

int Count;

#define endl '\n'

list<char> Keylogger()
{
	string keylog;
	cin >> keylog;

	list<char> password;
	auto cursor = password.begin();

	for (const auto& key : keylog)
	{
		switch (key)
		{
			case '<':
			{
				if (cursor != password.begin())
					cursor--;

				break;
			}

			case '>':
			{
				if (cursor != password.end())
					cursor++;

				break;
			}

			case '-':
			{
				if (cursor != password.begin())
					cursor = password.erase(--cursor);

				break;
			}

			default:
			{
				// 현재 커서 위치에 문자 삽입 (커서는 삽입된 문자 뒤에 위치하게 됨)
				password.insert(cursor, key);

				break;
			}
		}
	}

	return password;
}

void Print(const list<char>& InPassword)
{
	for (const auto& word : InPassword)
		cout << word;

	cout << endl;
}

void Solution()
{
	cin >> Count;
	
	while (Count--)
	{
		list<char> password = Keylogger();

		Print(password);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	Solution();

	return 0;
}
